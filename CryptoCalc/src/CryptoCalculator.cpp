#include "CryptoCalculator.hpp"
#include <iostream>
#include <iomanip>

CryptoCalculator::CryptoCalculator(
    std::unique_ptr<IFileHandler> handler,
    std::unique_ptr<IMarketSimulator> sim
) : handler_(std::move(handler)),
    sim_(std::move(sim))
{}

void CryptoCalculator::run() {
    try {
        std::string txt, bin;
        char resp;

        std::cout << "Text-file to load: ";
        std::cin  >> txt;
        loadTx(txt, false);

        std::cout << "Save as binary? (y/n): ";
        std::cin  >> resp;
        if (resp=='y'||resp=='Y') {
            std::cout << "Binary filename: ";
            std::cin  >> bin;
            handler_->saveBinary(bin, txs_);
        }

        std::cout << "Reload from binary? (y/n): ";
        std::cin  >> resp;
        if (resp=='y'||resp=='Y') {
            txs_.clear();
            std::cout << "Binary filename: ";
            std::cin  >> bin;
            loadTx(bin, true);
        }

        int days;
        double init;
        std::cout << "Days to simulate: ";
        std::cin  >> days;
        std::cout << "Initial price:   ";
        std::cin  >> init;
        simulate(days, init);

        computePnL();
        display();
    }
    catch (const FileException& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Unexpected: " << e.what() << std::endl;
    }
}

void CryptoCalculator::loadTx(const std::string& file, bool binary) {
    txs_ = binary
         ? handler_->loadBinary(file)
         : handler_->loadText(file);
}

void CryptoCalculator::simulate(int days, double initPrice) {
    prices_ = sim_->simulate(days, initPrice);
}

void CryptoCalculator::computePnL() {
    netPnl_ = 0.0;
    if (prices_.empty()) return;
    double p = prices_[0];
    for (const auto& tx : txs_) {
        double value = tx->getQuantity() * p;
        if (tx->getType() == TransactionType::SELL)
            netPnl_ += value;
        else
            netPnl_ -= value;
    }
}

void CryptoCalculator::display() const {
    // set fixed two-decimal formatting for all output
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "\n--- Transactions ---\n";
    for (const auto& tx : txs_)
        tx->print();

    std::cout << "\n--- Simulated Prices ---\n";
    for (double d : prices_)
        std::cout << d << "\n";

    std::cout << "\nNet P/L: $" << netPnl_ << "\n";
}
