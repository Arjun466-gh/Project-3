#pragma once
#include <string>
#include <vector>

// Abstract interface for any file‐based loader
template<typename T>
class FileLoader {
public:
    virtual ~FileLoader() = default;
    // Load objects of type T from a line‐oriented data file
    virtual std::vector<T> load(const std::string &filepath) const = 0;
};
