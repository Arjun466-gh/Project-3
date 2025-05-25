#include "Transaction.hpp"
#include <iostream>
#include <iomanip>

Transaction::Transaction(const std::string& coin,
                         int quantity,
                         double pricePerCoin,
                         TransactionType type)
  : coin_(coin),
    quantity_(quantity),
    pricePerCoin_(pricePerCoin),
    type_(type)
{}

std::string Transaction::getCoin() const { return coin_; }
int         Transaction::getQuantity() const { return quantity_; }
double      Transaction::getPricePerCoin() const { return pricePerCoin_; }
TransactionType Transaction::getType() const { return type_; }

void Transaction::print() const {
    // use ASCII 'x' and two-decimal fixed formatting
    std::cout << std::fixed << std::setprecision(2)
              << (type_ == TransactionType::BUY ? "BUY  " : "SELL ")
              << quantity_ << 'x' << coin_
              << " @ $" << pricePerCoin_
              << std::endl;
}
