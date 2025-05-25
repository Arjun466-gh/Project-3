#pragma once

#include <string>
#include <iostream>

enum class TransactionType { BUY = 0, SELL = 1 };

class Transaction {
public:
    Transaction(const std::string& coin,
                int quantity,
                double pricePerCoin,
                TransactionType type);

    std::string getCoin() const;
    int getQuantity() const;
    double getPricePerCoin() const;
    TransactionType getType() const;

    void print() const;

private:
    std::string coin_;
    int quantity_;
    double pricePerCoin_;
    TransactionType type_;
};
