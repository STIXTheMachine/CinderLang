//
// Created by jsoar on 6/11/2026.
//

#include "Utils.hpp"
std::vector<std::string_view> Utils::Split(const std::string_view& String, char Char)
{
    if (String.empty()) return std::vector<std::string_view> {};

    std::vector<std::string_view> Output;

    auto SubstrStart = String.cbegin();
    for (auto SubstrEnd = String.cbegin(); SubstrEnd < String.cend(); ++SubstrEnd)
    {
        if (*SubstrEnd == Char)
        {
            Output.emplace_back(SubstrStart, SubstrEnd);
            SubstrStart = SubstrEnd + 1;
        }
    }
    Output.emplace_back(SubstrStart, String.cend());

    return Output;
}
