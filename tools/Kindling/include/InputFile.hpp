//
// Created by jsoar on 6/14/2026.
//

#pragma once
#include <filesystem>
#include <vector>
#include "ErrorHandling.hpp"

// A buffered read-only representation of an input file
struct InputFile
{
    [[nodiscard]] Result<void> Load(const std::filesystem::path&);
    [[nodiscard]] const std::filesystem::path& Path() const { return FilePath; }
    void Reset();

    std::string_view Content {};
    std::span<const std::string_view> Lines {};

private:
    std::filesystem::path FilePath {};
    std::string ContentBuffer {};
    std::vector<std::string_view> LinesBuffer {};
};
