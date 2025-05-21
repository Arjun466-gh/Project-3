#include "PricePoint.hpp"
#include <sstream>
#include <iomanip>
#include <ctime>

PricePoint PricePoint::fromCsv(const std::string &line) {
    std::istringstream ss(line);
    std::string date;
    double price;
    std::getline(ss, date, ',');
    ss >> price;

    std::tm tm = {};
    std::istringstream ds(date);
    ds >> std::get_time(&tm, "%Y-%m-%d");
    auto tp = std::chrono::system_clock::from_time_t(std::mktime(&tm));

    return {tp, price};
}
