//
// Created by jsoar on 6/10/2026.
//
#include <print>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "EnumGenerator.hpp"
#include "LexemeStringGenerator.hpp"

int main(int argc, char* argv[])
{
    std::println("\n================ [CinderTokGen] Generating Tokens... ================");

    if (argc < 3)
    {
        std::println("Please specify both the input and output filepaths.");
        return -1;
    }

    const std::filesystem::path InputFilePath { argv[1] };

    if (!exists(InputFilePath))
    {
        std::println(std::cerr, "{} not found", weakly_canonical(InputFilePath).string());
        return -1;
    }

    std::println(std::cerr, "Generating tokens from {}...", weakly_canonical(InputFilePath).string());


    std::ifstream InputFile { InputFilePath };

    const std::filesystem::path OutputFilePath { argv[2] };
    if (!exists(OutputFilePath))
    {
        std::filesystem::create_directories(OutputFilePath.parent_path());
    }

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