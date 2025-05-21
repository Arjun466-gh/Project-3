#include "Transaction.hpp"
#include <sstream>

Transaction Transaction::fromCsv(const std::string &line) {
    std::istringstream ss(line);
    std::string date, typeStr, symbol;
    double amt;

    std::getline(ss, date, ',');
    std::getline(ss, typeStr, ',');
    std::getline(ss, symbol, ',');
    ss >> amt;

    // parse date if you want real timestamp; placeholder here
    TxType type = (typeStr == "BUY" ? TxType::BUY : TxType::SELL);

    return {/*timestamp=*/{}, symbol, type, amt};
}
