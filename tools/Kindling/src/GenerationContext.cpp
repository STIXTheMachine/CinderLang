//
// Created by jsoar on 6/13/2026.
//

#include "GenerationContext.hpp"
#include "Utils.hpp"
#include "ErrorHandling.hpp"
#include <fstream>
#include <algorithm>
#include <iostream>



GenerationContext& GenerationContext::AddDependency(const Dependency& InDependency)
{
    if (!std::ranges::contains(Dependencies, InDependency))
    {
        Dependencies.push_back(InDependency);
    }

    return *this;
}

GenerationContext& GenerationContext::AddDependencies(const std::span<const Dependency> Deps)
{
    for (auto& Dep : Deps)
    {
        AddDependency(Dep);
    }
    return *this;
}

GenerationContext& GenerationContext::AddDependencies(const std::initializer_list<Dependency> Deps)
{
    for (auto& Dep : Deps)
    {
        AddDependency(Dep);
    }
    return *this;
}

Result<void> GenerationContext::LoadInputFile(const std::filesystem::path& InputFilePath)
{
    Input.Reset();
    return Input.Load(InputFilePath);
}

Result<void> GenerationContext::Commit()
{
    ResolveDependencies();
    return Output.WriteToFile();
}

void GenerationContext::ResolveDependencies()
{
    Output.AddPreambleLine("#pragma once\n");
    std::ranges::sort(Dependencies);
    std::string Include;

    for (const auto& Dependency : Dependencies)
    {
        switch (Dependency.Type)
        {
            case Dependency::Type::System:
                Include = format("#include <{}>", Dependency.Name);
                break;
            case Dependency::Type::Local:
                Include = format("#include \"{}\"", Dependency.Name);
                break;
        }

        Output.AddPreambleLine(Include);
    }
}
