//
// Created by jsoar on 6/11/2026.
//

#pragma once
#include <fstream>

struct GeneratorBase
{
    GeneratorBase(std::ifstream& InputFile, std::ofstream& OutputFile) : InputFile(InputFile), OutputFile(OutputFile) { };
    virtual ~GeneratorBase() = default;

    virtual void Generate() = 0;

protected:
    std::ifstream& InputFile;
    std::ofstream& OutputFile;
};
