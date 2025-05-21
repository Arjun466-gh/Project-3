#pragma once
#include <string>
#include <chrono>

enum class TxType { BUY, SELL };

struct Transaction {
    std::chrono::system_clock::time_point timestamp;
    std::string symbol;
    TxType type;
    double amount;

    //CSV line: "YYYY-MM-DD,TYPE,SYMBOL,AMOUNT"
    static Transaction fromCsv(const std::string &line);
};
