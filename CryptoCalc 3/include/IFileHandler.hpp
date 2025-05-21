#pragma once

#include <vector>
#include <memory>
#include <string>
#include <stdexcept>
#include "Transaction.hpp"

class FileException : public std::runtime_error {
public:
    explicit FileException(const std::string& msg)
      : std::runtime_error("File I/O error: " + msg) {}
};

class IFileHandler {
public:
    virtual ~IFileHandler() = default;

    // Throws FileException on failure
    virtual std::vector<std::shared_ptr<Transaction>>
       loadText(const std::string& filename) = 0;

    virtual void saveText(const std::string& filename,
                          const std::vector<std::shared_ptr<Transaction>>& txs) = 0;

    virtual std::vector<std::shared_ptr<Transaction>>
       loadBinary(const std::string& filename) = 0;

    virtual void saveBinary(const std::string& filename,
                            const std::vector<std::shared_ptr<Transaction>>& txs) = 0;
};
