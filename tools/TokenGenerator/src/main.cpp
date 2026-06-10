//
// Created by jsoar on 6/10/2026.
//
#include <iostream>
#include <fstream>
#include <filesystem>

constexpr auto EnumStart = "enum class Token\n{\n";
constexpr auto EnumEnd = "\n}\n";

int main()
{
    const std::filesystem::path InputFolder = "../../../spec";
    const std::filesystem::path InputFile = InputFolder / "tokens.def";
    if (!exists(InputFile))
    {
        std::cerr << "tokens.def not found" << std::endl;
        return -1;
    }

    const std::filesystem::path OutputFolder = "../../generated";

    if (!exists(OutputFolder))
    {
        std::filesystem::create_directory(OutputFolder);
    }

    const std::filesystem::path OutputPath = OutputFolder / "Token.generated.h";
    std::ofstream OutputFile { OutputPath };

    OutputFile << EnumStart;
    OutputFile << "Hello, World!";
    OutputFile << EnumEnd;
}