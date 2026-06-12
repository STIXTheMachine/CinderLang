//
// Created by jake_ on 6/12/2026.
//

#pragma once
#include "GeneratorBase.hpp"


struct TableGenerator : public GeneratorBase
{
    using GeneratorBase::GeneratorBase;
    virtual void Generate() override;
};
