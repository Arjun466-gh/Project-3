#include "CryptoCalculator.hpp"
#include "FileHandler.hpp"
#include "RandomMarketSimulator.hpp"
#include <memory>

int main() {
    auto handler = std::make_unique<FileHandler>();
    auto sim     = std::make_unique<RandomMarketSimulator>(5.0);

    CryptoCalculator app(std::move(handler), std::move(sim));
    app.run();
    return 0;
}
