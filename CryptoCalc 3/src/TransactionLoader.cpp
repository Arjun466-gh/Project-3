#include "TransactionLoader.hpp"
#include <fstream>
#include <string>

std::vector<Transaction> TransactionLoader::load(const std::string &filepath) const {
    std::vector<Transaction> result;
    std::ifstream in(filepath);
    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        result.push_back(Transaction::fromCsv(line));
    }
    return result;
}
