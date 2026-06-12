//
// Created by jake_ on 6/12/2026.
//

#include "TableGenerator.h"

#include "Utils.hpp"

void TableGenerator::Generate()
{
    ResetInputFile();

    auto Content = Utils::ReadToString(InputFile);

    for (const auto& Line : Utils::Split(Content, '\n'))
    {

    }
}
