//
// Created by jsoar on 6/9/2026.
//

#pragma once
#include <cstdint>
#include <optional>
#include <string_view>
#include "Token.generated.hpp"

class Token
{
    size_t Line   = 0;
    size_t Column = 0;
    size_t Length = 0;
};