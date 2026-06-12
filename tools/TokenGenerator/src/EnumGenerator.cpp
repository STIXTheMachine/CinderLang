//
// Created by jsoar on 6/11/2026.
//

#include "EnumGenerator.hpp"

#include <iostream>
#include <ranges>
#include "Utils.hpp"

constexpr auto EnumStart = "enum class TokenType\n{";
constexpr auto EnumEnd = "\n};\n";

void EnumGenerator::Generate()
{
    ResetInputFile();

    OutputFile << EnumStart;

    OutputFile << "\n\tSpecial_None,";
    OutputFile << "\n\tSpecial_EOF,";

    const std::string InputString { std::istreambuf_iterator { InputFile }, {} };

    std::string Prefix;
    for (auto Line : Utils::Split(InputString, '\n'))
    {
        if (Line.empty())
        {
            continue;
        }

        // If line starts with "@ " we're defining the @ token's properties and do not need to do prefix generation
        if (Line.starts_with('@') && !Line.starts_with("@ "))
        {
            if (Line.length() > 1)
            {
                const auto Idx = Line.find(' ');
                const auto End = Idx == std::string_view::npos ? Line.cend() : Line.cbegin() + Idx;
                Prefix = std::string { Line.cbegin() + 1,  End } + '_';
                OutputFile << '\n';
            }

            continue;
        }

        std::vector<std::string_view> Fields = Utils::Split(Line, ' ');
        std::string_view Lexeme = Fields[0];
        std::string_view Name = Fields[1];

        OutputFile << "\n\t" << Prefix << Name << ',';
    }

    OutputFile << EnumEnd;
}

