#pragma once

#include "IFileHandler.hpp"
#include "IMarketSimulator.hpp"
#include <vector>
#include <memory>
#include <string>

class CryptoCalculator {
public:
    CryptoCalculator(std::unique_ptr<IFileHandler> handler,
                     std::unique_ptr<IMarketSimulator> sim);
    void run();

private:
    void loadTx(const std::string& file, bool binary);
    void simulate(int days, double initPrice);
    void computePnL();
    void display() const;

    std::unique_ptr<IFileHandler>   handler_;
    std::unique_ptr<IMarketSimulator> sim_;
    std::vector<std::shared_ptr<Transaction>> txs_;
    std::vector<double>             prices_;
    double                          netPnl_{0.0};
};
