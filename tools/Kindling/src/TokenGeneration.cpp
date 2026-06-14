//
// Created by jsoar on 6/12/2026.
//
#include "ErrorHandling.hpp"
#include "TokenGeneration.hpp"
#include "Utils.hpp"
#include <fstream>
#include <format>
#include <iostream>
#include <print>

namespace
{
    constexpr auto FormatBufferSize = 1024;
    char LineFormatBuffer[FormatBufferSize];

    template<typename... FmtArgs>
    const char* Format(std::format_string<FmtArgs...> FormatString, FmtArgs&&... Args)
    {
        auto Result = std::format_to_n(LineFormatBuffer, FormatBufferSize, FormatString, std::forward<FmtArgs>(Args)...);
        *Result.out = '\0';
        return LineFormatBuffer;
    }
}


TokenGenerator::TokenGenerator(
    const std::filesystem::path& InputFilePath,
    const std::filesystem::path& OutputFilePath
)
{
    Ctx.InputFilePath = InputFilePath;
    Ctx.OutputFilePath = OutputFilePath;
}

Result<void> TokenGenerator::Generate()
{
    TRY(Ctx.LoadInputFile())

    std::println("Generating from {}", weakly_canonical(Ctx.InputFilePath).string());
    std::println("Outputting to: {}", weakly_canonical(Ctx.OutputFilePath).string());
    std::fflush(stdout);

    TokenDefinitions.reserve(Ctx.InputFileLines.size());

    CreateSpecialTokens();

    TRY(ParseDefinitionFile())

    GenerateTokenTypeEnum();
    GenerateFixedLexemeStringViews();
    GenerateLookupFunctions();

    if (auto CommitResult = Ctx.Commit(); !CommitResult.has_value())
    {
        return CommitResult;
    }

    return {};
}

void TokenGenerator::CreateSpecialTokens()
{
    TokenDefinitions.emplace_back("Special", "", "None");
    TokenDefinitions.emplace_back("Special", "", "EOF");
}

Result<void> TokenGenerator::ParseDefinitionFile()
{
    if (Ctx.InputFileContents.empty())
    {
        FAIL(Format("Failed to parse file {}: file is empty", weakly_canonical(Ctx.InputFilePath).string()));
    }

    std::string Prefix;
    std::vector<std::string_view> Fields(2);

    for (const auto& Line : Ctx.InputFileLines)
    {
        if (Line.empty())
        {
            continue;
        }

        Fields = Utils::Split(Line, ' ');

        if (Fields.size() == 1 && Fields[0].starts_with('@'))
        {
            Prefix = Fields[0].substr(1);
            continue;
        }

        if (Fields.size() == 2)
        {
            TokenDefinitions.emplace_back(Prefix, std::string { Fields[0] }, std::string { Fields[1] });
            continue;
        }

        FAIL(Format("Error parsing {}: Line `{}` is malformed", weakly_canonical(Ctx.InputFilePath).string(), Line));
    }

    return {};
}

void TokenGenerator::GenerateTokenTypeEnum()
{
    Ctx.AddLine(Format("enum class {}", EnumClassName))
    .AddLine("{").Indent();

    for (const auto& [Prefix, Lexeme, Name] : TokenDefinitions)
    {
        Ctx.AddLine(Format("{}_{},", Prefix, Name));
    }

    Ctx.Dedent().AddLine("};").AddLine();
}

void TokenGenerator::GenerateFixedLexemeStringViews()
{
    Ctx.AddDependency(EDependencyType::System, "string_view");

    for (const auto& [Prefix, Lexeme, Name] : TokenDefinitions)
    {
        if (Prefix == "Special") continue;

        Ctx.AddLine(Format("static inline constexpr std::string_view {}String {{ R\"_LexStr_({})_LexStr_\" }};", Name, Lexeme));
    }

    Ctx.AddLine();
}

void TokenGenerator::GenerateLookupFunctions()
{
    Ctx.AddDependency(EDependencyType::System, "string_view")
       .AddDependency(EDependencyType::System,"unordered_map")
       .AddDependency(EDependencyType::Local,"ErrorHandling.hpp");


    // TokenType -> Lexeme Function
    Ctx.AddLine(Format("inline Option<std::string_view> GetLexemeForTokenType(const {} InTokenType)", EnumClassName))
    .AddLine("{").Indent()
    .AddLine(Format("static const std::unordered_map<{}, std::string_view> {}", EnumClassName, TokenToLexemeTableName))
    .AddLine("{").Indent();

    for (const auto& [Prefix, Lexeme, Name] : TokenDefinitions)
    {
        if (Prefix == "Special") continue;

        Ctx.AddLine(Format("{{ {}::{}_{}, {}String }},", EnumClassName, Prefix, Name, Name));
    }

    Ctx.Dedent()
    .AddLine("};")
    .AddLine(Format("const auto Result = {}.find(InTokenType);", TokenToLexemeTableName))
    .AddLine(Format("return Result == {}.cend() ? None : Option {{ Result->second }};", TokenToLexemeTableName))
    .Dedent().AddLine("}").AddLine();


    // Lexeme -> TokenType Function
    Ctx.AddLine(Format("inline Option<{}> GetTokenTypeForLexeme(const std::string_view InLexeme)", EnumClassName))
    .AddLine("{").Indent()
    .AddLine(Format("static const std::unordered_map<std::string_view, {}> {} ", EnumClassName, LexemeToTokenTableName))
    .AddLine("{").Indent();

    for (const auto& [Prefix, Lexeme, Name] : TokenDefinitions)
    {
        if (Prefix == "Special") continue;
        Ctx.AddLine(Format("{{ {}String, {}::{}_{} }},", Name, EnumClassName, Prefix, Name));
    }

    Ctx.Dedent()
    .AddLine("};")
    .AddLine(Format("const auto Result = {}.find(InLexeme);", LexemeToTokenTableName))
    .AddLine(Format("return Result == {}.cend() ? None : Option {{ Result->second }};", LexemeToTokenTableName))
    .Dedent().AddLine("}").AddLine();
}