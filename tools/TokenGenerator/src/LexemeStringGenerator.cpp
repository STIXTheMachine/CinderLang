//
// Created by jsoar on 6/11/2026.
//

#include "LexemeStringGenerator.hpp"
#include <print>
#include <iostream>

#include "Utils.hpp"

static constexpr auto DeclarationFormatString = R"_Decl(static inline constexpr std::string_view {}String = R"_LexStr_({})_LexStr_";)_Decl";

void LexemeStringGenerator::Generate()
{
    ResetInputFile();

    const std::string Contents { std::istreambuf_iterator { InputFile }, {} };
    if (Contents.empty())
    {
        std::print("{}: Failed to read information from input file.", __PRETTY_FUNCTION__);
    }
    for (auto Line : Utils::Split(Contents,'\n'))
    {
        if (Line.empty() || (Line.starts_with('@') && !Line.starts_with("@ ")))
        {
            continue;
        }

        std::vector<std::string_view> Fields = Utils::Split(Line, ' ');
        std::string_view Lexeme = Fields[0];
        std::string_view Name = Fields[1];

        OutputFile << std::format(DeclarationFormatString, Name, Lexeme) << std::endl;
    }
}
