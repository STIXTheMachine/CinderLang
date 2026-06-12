//
// Created by jsoar on 6/10/2026.
//
#include <print>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "EnumGenerator.hpp"
#include "LexemeStringGenerator.hpp"


int main()
{
    std::println("\n================ [CinderTokGen] Generating Tokens... ================");

    const std::filesystem::path InputFolder = "../spec";
    const std::filesystem::path InputFilePath = InputFolder / "tokens.def";
    if (!exists(InputFilePath))
    {
        std::println(std::cerr, "{} not found", weakly_canonical(InputFilePath).string());
        return -1;
    }

    std::ifstream InputFile { InputFilePath };

    const std::filesystem::path OutputFolder = "./generated";
    if (!exists(OutputFolder))
    {
        std::filesystem::create_directory(OutputFolder);
    }

    const std::filesystem::path OutputFilePath = OutputFolder / "Token.generated.hpp";
    std::println("Output: {}", weakly_canonical(OutputFilePath).string());
    if (exists(OutputFilePath))
    {
        std::filesystem::remove(OutputFilePath);
    }
    std::ofstream OutputFile { OutputFilePath, std::ios::app };

    EnumGenerator EnumGenerator { InputFile, OutputFile };
    EnumGenerator.Generate();
    
    LexemeStringGenerator LexemeStringGenerator { InputFile, OutputFile };
    LexemeStringGenerator.Generate();

    std::println("================ [CinderTokGen] Tokens Generated! ================\n");
}