//
// Created by jsoar on 6/9/2026.
//

#pragma once
#include "Token.generated.hpp"

class Token
{
    ETokenType Type = ETokenType::Special_None;
    size_t Line   = 0;
    size_t Column = 0;
    size_t Length = 0;
};