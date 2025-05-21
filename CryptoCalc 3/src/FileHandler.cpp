#include "FileHandler.hpp"

std::vector<std::shared_ptr<Transaction>>
FileHandler::loadText(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) throw FileException("open " + filename);

    std::vector<std::shared_ptr<Transaction>> result;
    std::string coin;
    int qty; double price; int type;
    while (in >> coin >> qty >> price >> type) {
        result.push_back(std::make_shared<Transaction>(
            coin, qty, price, static_cast<TransactionType>(type)
        ));
    }
    return result;
}

void FileHandler::saveText(const std::string& filename,
                           const std::vector<std::shared_ptr<Transaction>>& txs) {
    std::ofstream out(filename);
    if (!out) throw FileException("open " + filename);

    for (auto& tx : txs) {
        out << tx->getCoin() << ' '
            << tx->getQuantity() << ' '
            << tx->getPricePerCoin() << ' '
            << static_cast<int>(tx->getType())
            << '\n';
    }
}

std::vector<std::shared_ptr<Transaction>>
FileHandler::loadBinary(const std::string& filename) {
    std::ifstream in(filename, std::ios::binary);
    if (!in) throw FileException("open " + filename);

    std::vector<std::shared_ptr<Transaction>> result;
    while (in.peek() != EOF) {
        size_t len;
        in.read(reinterpret_cast<char*>(&len), sizeof(len));
        std::string coin(len, '\0');
        in.read(&coin[0], len);

        int qty;
        double price;
        int type;
        in.read(reinterpret_cast<char*>(&qty), sizeof(qty));
        in.read(reinterpret_cast<char*>(&price), sizeof(price));
        in.read(reinterpret_cast<char*>(&type), sizeof(type));

        result.push_back(std::make_shared<Transaction>(
            coin, qty, price, static_cast<TransactionType>(type)
        ));
    }
    return result;
}

void FileHandler::saveBinary(const std::string& filename,
                             const std::vector<std::shared_ptr<Transaction>>& txs) {
    std::ofstream out(filename, std::ios::binary);
    if (!out) throw FileException("open " + filename);

    for (auto& tx : txs) {
        size_t len = tx->getCoin().size();
        out.write(reinterpret_cast<char*>(&len), sizeof(len));
        out.write(tx->getCoin().c_str(), len);

        int qty        = tx->getQuantity();
        double price   = tx->getPricePerCoin();
        int type       = static_cast<int>(tx->getType());
        out.write(reinterpret_cast<char*>(&qty),    sizeof(qty));
        out.write(reinterpret_cast<char*>(&price),  sizeof(price));
        out.write(reinterpret_cast<char*>(&type),   sizeof(type));
    }
}
