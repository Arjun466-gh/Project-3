#pragma once

#include "IFileHandler.hpp"
#include <fstream>

class FileHandler : public IFileHandler {
public:
    std::vector<std::shared_ptr<Transaction>>
      loadText(const std::string& filename) override;

    void saveText(const std::string& filename,
                  const std::vector<std::shared_ptr<Transaction>>& txs) override;

    std::vector<std::shared_ptr<Transaction>>
      loadBinary(const std::string& filename) override;

    void saveBinary(const std::string& filename,
                    const std::vector<std::shared_ptr<Transaction>>& txs) override;
};
