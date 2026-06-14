//
// Created by jsoar on 6/14/2026.
//

#include "OutputFile.hpp"
#include <fstream>
#include <iostream>

OutputFile& OutputFile::Indent()
{
    IndentLevel += 1;
    return *this;
}

OutputFile& OutputFile::Dedent()
{
    if (IndentLevel == 0) [[unlikely]]
    {
        std::cerr << "Warning: attempting to dedent beyond indentation level 0";
    }
    else
    {
        --IndentLevel;
    }

    return *this;
}

OutputFile& OutputFile::AddLine(const std::string_view Line)
{
    Buffer << '\n';
    for (auto Idx = 0; Idx < IndentLevel; ++Idx)
    {
        Buffer << '\t';
    }
    Buffer << Line;
    return *this;
}
OutputFile& OutputFile::AddLine()
{
    Buffer << '\n';
    return *this;
}

OutputFile& OutputFile::AddPreambleLine(std::string_view Line)
{
    Preamble << Line << '\n';
    return *this;
}

OutputFile& OutputFile::AddPreambleLine()
{
    Preamble << '\n';
    return *this;
}

Result<void> OutputFile::WriteToFile() const
{
    if (FilePath.empty())
    {
        FAIL("Attempting to generate to empty file path");
    }

    std::error_code ErrorCode;

    if (exists(FilePath))
    {
        remove(FilePath, ErrorCode);
        if (ErrorCode)
        {
            FAIL(format("Failed to generate file {}: {}", weakly_canonical(FilePath).string(), ErrorCode.message()));
        }
    }

    create_directories(FilePath.parent_path(), ErrorCode);
    if (ErrorCode)
    {
        FAIL(format("Failed to generate file {}: {}", weakly_canonical(FilePath).string(), ErrorCode.message()));
    }

    std::ofstream OutputStream { FilePath, std::ios::trunc };
    OutputStream << Preamble.str() << Buffer.str();
    OutputStream.close();

    return {};
}

void OutputFile::Reset()
{
    FilePath    = "";
    IndentLevel = 0;
    Buffer.clear();
}
