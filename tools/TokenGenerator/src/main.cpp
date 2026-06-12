//
// Created by jsoar on 6/10/2026.
//
#include <iostream>
#include <fstream>
#include <filesystem>
#include "EnumGenerator.hpp"


int main()
{
    const std::filesystem::path InputFolder = "../../../spec";
    const std::filesystem::path InputFilePath = InputFolder / "tokens.def";
    if (!exists(InputFilePath))
    {
        std::cerr << "tokens.def not found" << std::endl;
        return -1;
    }

    std::ifstream InputFile { InputFilePath };

    const std::filesystem::path OutputFolder = "../../generated";
    if (!exists(OutputFolder))
    {
        std::filesystem::create_directory(OutputFolder);
    }

    const std::filesystem::path OutputFilePath = OutputFolder / "Token.generated.h";
    if (exists(OutputFilePath))
    {
        std::filesystem::remove(OutputFilePath);
    }
    std::ofstream OutputFile { OutputFilePath };

    EnumGenerator EnumGenerator { InputFile, OutputFile };
    EnumGenerator.Generate();
}
