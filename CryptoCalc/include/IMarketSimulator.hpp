#pragma once

#include <vector>

class IMarketSimulator {
public:
    virtual ~IMarketSimulator() = default;
    virtual std::vector<double>
      simulate(int days, double initialPrice) const = 0;
};
