//
// Created by jsoar on 6/13/2026.
//

#pragma once
#include "ErrorHandling.hpp"
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


enum class EDependencyType { System, Local };

struct GenerationContext
{
    GenerationContext& AddDependency(EDependencyType type, std::string Name);
    GenerationContext& Indent();
    GenerationContext& Dedent();
    GenerationContext& AddLine(std::string_view Line);
    GenerationContext& AddLine();

    [[nodiscard]] Result<void> LoadInputFile();
    [[nodiscard]] Result<void> Commit();

    std::filesystem::path         InputFilePath {};
    std::filesystem::path         OutputFilePath {};
    std::string                   InputFileContents {};
    std::vector<std::string_view> InputFileLines {};
    std::ostringstream            FileContentBuffer {};

private:
    [[nodiscard]] Result<std::ofstream> TryCreateOutputStream() const;
    void GenerateHeaders();
    void WriteContentsToFile();
    uint32_t IndentLevel {};

    std::ofstream OutputFileStream;
    std::vector<std::string> Dependencies {};
};
