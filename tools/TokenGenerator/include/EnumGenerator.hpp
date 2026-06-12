//
// Created by jsoar on 6/11/2026.
//

#pragma once
#include <fstream>

class EnumGenerator
{
public:
    EnumGenerator(std::ifstream& InputFile, std::ofstream& OutputFile);

    void Generate();

private:
    std::ifstream& InputFile;
    std::ofstream& OutputFile;
};
