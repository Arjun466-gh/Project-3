#include "PriceLoader.hpp"
#include <fstream>
#include <string>

std::vector<PricePoint> PriceLoader::load(const std::string &filepath) const {
    std::vector<PricePoint> result;
    std::ifstream in(filepath);
    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        result.push_back(PricePoint::fromCsv(line));
    }
    return result;
}
