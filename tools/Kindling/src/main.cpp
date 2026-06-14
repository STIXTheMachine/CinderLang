//
// Created by jsoar on 6/10/2026.
//
#include <print>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "TokenGeneration.hpp"

int main(int argc, char* argv[])
{
    // Validate that we at least got two file paths passed
    if (argc < 3)
    {
        std::println("Please specify both the input and output filepaths.");
        return -1;
    }

    std::println("\n================ [Kindling] Generating Tokens... ================");
    TokenGenerator TokenGenerator { argv[1], argv[2] };
    if (auto TokenPassResult = TokenGenerator.Generate(); !TokenPassResult.has_value())
    {
        std::cerr << TokenPassResult.error();
        return -1;
    }
    std::println("================ [Kindling] Tokens Generated! ================\n");


}