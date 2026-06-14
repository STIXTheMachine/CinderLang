//
// Created by jsoar on 6/12/2026.
//

#pragma once
#include <expected>
#include "GenerationContext.hpp"

struct TokenGenerator
{
    TokenGenerator(const std::filesystem::path& InputFilePath, const std::filesystem::path& OutputFilePath);
    GenerationContext Ctx;

    [[nodiscard]] Result<void> Generate();

private:
    std::filesystem::path InputFilePath;
    std::filesystem::path OutputFilePath;

    static constexpr auto EnumClassName = "ETokenType";
    static constexpr auto LexemeToTokenTableName = "LexemeToTokenType";
    static constexpr auto TokenToLexemeTableName = "TokenTypeToLexeme";

    struct TokenDefinition
    {
        std::string Prefix;
        std::string Lexeme;
        std::string Name;
    };

    std::vector<TokenDefinition> TokenDefinitions;

    [[nodiscard]] Result<void> ParseDefinitionFile();

    void CreateSpecialTokens();
    void GenerateTokenTypeEnum();
    void GenerateFixedLexemeStringViews();
    void GenerateLookupFunctions();
};
