#include "CryptoCalculator.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "Usage: crypto_calc <prices.csv> <transactions.csv>\n";
        return 1;
    }
    CryptoCalculator app(argv[1], argv[2]);
    app.run();
    return 0;
}
