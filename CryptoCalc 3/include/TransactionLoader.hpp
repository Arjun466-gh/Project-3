#pragma once
#include "FileLoader.hpp"
#include "Transaction.hpp"

class TransactionLoader : public FileLoader<Transaction> {
public:
    std::vector<Transaction> load(const std::string &filepath) const override;
};
