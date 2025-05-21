#pragma once
#include <vector>
#include <string>
#include "PricePoint.hpp"
#include "Transaction.hpp"

class CryptoCalculator {
public:
    CryptoCalculator(const std::string &priceFile,
                     const std::string &txFile);
    ~CryptoCalculator() = default;

    // data loading and computation
    void run();

private:
    std::vector<PricePoint> prices_;
    std::vector<Transaction> transactions_;
    std::string priceFile_, txFile_;

    void loadData();
    void computePnL() const;
    void report() const;
};
