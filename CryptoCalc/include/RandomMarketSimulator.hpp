#pragma once

#include "IMarketSimulator.hpp"
#include <random>

class RandomMarketSimulator : public IMarketSimulator {
public:
    explicit RandomMarketSimulator(double volatilityPercent = 5.0);
    std::vector<double>
      simulate(int days, double initialPrice) const override;

private:
    double volatilityPercent_;
};
