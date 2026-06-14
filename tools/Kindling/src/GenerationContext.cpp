//
// Created by jsoar on 6/13/2026.
//

#include "GenerationContext.hpp"
#include "Utils.hpp"
#include "ErrorHandling.hpp"
#include <fstream>
#include <algorithm>

GenerationContext& GenerationContext::AddDependency(EDependencyType Type, std::string Name)
{
    std::string Header;
    Header.reserve(32);
    Header = "#include ";

    switch(Type)
    {
        case EDependencyType::System:
            Header += '<' + Name + '>';
            break;
        case EDependencyType::Local:
            Header += '"' + Name + '"';
            break;
    }

    if (!std::ranges::contains(Dependencies, Header))
    {
        Dependencies.emplace_back(std::move(Header));
    }

    return *this;
}

GenerationContext& GenerationContext::Indent()
{
    IndentLevel += 1;
    return *this;
}
GenerationContext& GenerationContext::Dedent()
{
    IndentLevel -= IndentLevel == 0 ? 0 : 1;
    return *this;
}

GenerationContext& GenerationContext::AddLine(const std::string_view Line)
{
    FileContentBuffer << '\n';
    for (auto Idx = 0; Idx < IndentLevel; ++Idx)
    {
        FileContentBuffer << '\t';
    }
    FileContentBuffer << Line;
    return *this;
}

GenerationContext& GenerationContext::AddLine()
{
    FileContentBuffer << '\n';
    return *this;
}

Result<void> GenerationContext::LoadInputFile()
{
    if (!exists(InputFilePath))
    {
       FAIL(std::format("Failed to open file {}", weakly_canonical(InputFilePath).string()));
    }

    InputFileContents = Utils::ReadFileToString(InputFilePath);
    InputFileLines = Utils::Split(InputFileContents, '\n');
    return {};
}

void GenerationContext::GenerateHeaders() {
    OutputFileStream << "#pragma once\n";

    for (const auto& Dependency : Dependencies)
    {
        OutputFileStream << Dependency << '\n';
    }
}

void GenerationContext::WriteContentsToFile()
{
    OutputFileStream << FileContentBuffer.str();
}

Result<void> GenerationContext::Commit()
{
    TRY_ASSIGN(OutputFileStream, TryCreateOutputStream());

    GenerateHeaders();
    WriteContentsToFile();

    return {};
}

Result<std::ofstream> GenerationContext::TryCreateOutputStream() const
{
    std::error_code ErrorCode;
    if (exists(OutputFilePath))
    {
        std::filesystem::remove(OutputFilePath, ErrorCode);
        if (ErrorCode)
        {
            FAIL(std::format("Failed to generate file {}: {}", weakly_canonical(OutputFilePath).string(), ErrorCode.message()));
        }
    }

    std::filesystem::create_directories(OutputFilePath.parent_path(), ErrorCode);
    if (ErrorCode)
    {
        FAIL(std::format("Failed to generate file {}: {}", weakly_canonical(OutputFilePath).string(), ErrorCode.message()));
    }

    return std::ofstream { OutputFilePath, std::ios::trunc };
}
