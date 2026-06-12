//
// Created by jsoar on 6/11/2026.
//

#include "GeneratorBase.hpp"

void GeneratorBase::ResetInputFile() const
{
    InputFile.clear();
    InputFile.seekg(0, std::ios::beg);
}
