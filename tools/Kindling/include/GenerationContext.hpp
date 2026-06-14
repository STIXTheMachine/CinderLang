//
// Created by jsoar on 6/13/2026.
//

#pragma once
#include "ErrorHandling.hpp"
#include "InputFile.hpp"
#include "OutputFile.hpp"
#include <filesystem>
#include <fstream>
#include <sstream>
#include <vector>

struct Dependency
{
    enum class Type { System, Local };

    Type Type = Type::System;
    std::string_view Name;
    auto operator<=>(const Dependency&) const = default;
};

struct GenerationContext
{
    GenerationContext& AddDependency(const Dependency&);
    GenerationContext& AddDependencies(std::span<const Dependency>);
    GenerationContext& AddDependencies(std::initializer_list<Dependency>);

    InputFile Input {};
    OutputFile Output {};

    [[nodiscard]] Result<void> LoadInputFile(const std::filesystem::path&);
    [[nodiscard]] Result<void> Commit();
    void ResolveDependencies();

private:
    std::vector<Dependency> Dependencies {};
};
