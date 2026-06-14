//
// Created by jsoar on 6/14/2026.
//

#include "InputFile.hpp"
#include "Utils.hpp"

Result<void> InputFile::Load(const std::filesystem::path& InFilePath)
{
    if (InFilePath.empty())
    {
        FAIL("Attempted to load from empty file path.");
    }

    if (!exists(InFilePath))
    {
        FAIL(std::format("Failed to open file {}", weakly_canonical(InFilePath).string()));
    }

    FilePath = InFilePath;

    ContentBuffer = Utils::ReadFileToString(FilePath);
    Content       = { ContentBuffer.cbegin(), ContentBuffer.cend() };

    LinesBuffer = Utils::Split(Content, '\n');
    Lines       = std::span { LinesBuffer.cbegin(), LinesBuffer.cend() };

    return {};
}

void InputFile::Reset()
{
    FilePath = std::filesystem::path {};
    Content  = "";
    Lines    = {};
    ContentBuffer.clear();
    LinesBuffer.clear();
}
