#pragma once
#include <string>
#include <chrono>

struct PricePoint {
    std::chrono::system_clock::time_point timestamp;
    double price;

    // CSV line: "YYYY-MM-DD,PRICE"
    static PricePoint fromCsv(const std::string &line);
};
