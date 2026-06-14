//
// Created by jsoar on 6/11/2026.
//

#pragma once
#include <filesystem>
#include <string_view>
#include <vector>

namespace Utils
{
    std::vector<std::string_view> Split(const std::string_view& String, char Char);
    std::vector<std::string_view> Split(std::string&&, char Char) = delete; // Unsafe

    std::string ReadFileToString(std::ifstream& FileStream);
    std::string ReadFileToString(const std::filesystem::path& Path);
}