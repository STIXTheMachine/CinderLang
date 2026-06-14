//
// Created by jsoar on 6/14/2026.
//

#pragma once
#include "ErrorHandling.hpp"
#include <filesystem>
#include <sstream>

struct OutputFile
{
    OutputFile& Indent();
    OutputFile& Dedent();
    OutputFile& AddLine(std::string_view Line);
    OutputFile& AddLine();
    OutputFile& AddPreambleLine(std::string_view Line);
    OutputFile& AddPreambleLine();

    std::filesystem::path FilePath {};

private:
    friend struct GenerationContext;
    uint32_t IndentLevel {};
    std::ostringstream Buffer {};
    std::ostringstream Preamble {};

    [[nodiscard]] Result<void> WriteToFile() const;
    void          Reset();
};
