#include "CryptoCalculator.hpp"
#include "PriceLoader.hpp"
#include "TransactionLoader.hpp"
#include <iostream>

CryptoCalculator::CryptoCalculator(const std::string &priceFile,
                                   const std::string &txFile)
    : priceFile_(priceFile), txFile_(txFile) {}

void CryptoCalculator::run() {
    loadData();
    computePnL();
    report();
}

void CryptoCalculator::loadData() {
    PriceLoader pl;
    TransactionLoader tl;
    prices_ = pl.load(priceFile_);
    transactions_ = tl.load(txFile_);
}

void CryptoCalculator::computePnL() const {
    // TODO: implement P/L computation logic
}

void CryptoCalculator::report() const {
    std::cout << "Loaded " << prices_.size()
              << " price points and " << transactions_.size()
              << " transactions.\n";
}
