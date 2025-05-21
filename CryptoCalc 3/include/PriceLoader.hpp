#pragma once
#include "FileLoader.hpp"
#include "PricePoint.hpp"

class PriceLoader : public FileLoader<PricePoint> {
public:
    std::vector<PricePoint> load(const std::string &filepath) const override;
};
