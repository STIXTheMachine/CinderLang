//
// Created by jsoar on 6/11/2026.
//

#pragma once
#include <filesystem>
#include <string_view>
#include <vector>

class Utils
{
public:
    static std::vector<std::string_view> Split(const std::string_view& String, char Char);
    static std::string ReadFileToString(std::ifstream& FileStream);
    static std::string ReadFileToString(const std::filesystem::path& Path);
};