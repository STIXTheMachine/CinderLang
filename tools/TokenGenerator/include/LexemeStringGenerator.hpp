//
// Created by jsoar on 6/11/2026.
//

#pragma once
#include "GeneratorBase.hpp"

struct LexemeStringGenerator : public GeneratorBase
{
    using GeneratorBase::GeneratorBase;
    void Generate() override;
};
