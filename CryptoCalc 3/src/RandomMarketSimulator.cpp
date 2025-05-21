#include "RandomMarketSimulator.hpp"

RandomMarketSimulator::RandomMarketSimulator(double volatilityPercent)
  : volatilityPercent_(volatilityPercent) {}

std::vector<double>
RandomMarketSimulator::simulate(int days,
                                double initialPrice) const {
    std::vector<double> prices;
    prices.reserve(days);

    std::mt19937            gen(std::random_device{}());
    std::uniform_real_distribution<> dist(
      -volatilityPercent_/100.0,
       volatilityPercent_/100.0
    );

    double p = initialPrice;
    for (int i = 0; i < days; ++i) {
        p *= (1 + dist(gen));
        prices.push_back(p);
    }
    return prices;
}
