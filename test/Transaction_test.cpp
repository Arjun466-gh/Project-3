#include "Transaction.hpp"
#include <gtest/gtest.h>

// Test fixture for Transaction
class TransactionTest : public ::testing::Test {
protected:
    Transaction buyTransaction{"BTC", 10, 50000.0, TransactionType::BUY};
    Transaction sellTransaction{"ETH", 5, 2500.0, TransactionType::SELL};
};

TEST_F(TransactionTest, GetCoinReturnsCorrectValue) {
    EXPECT_EQ(buyTransaction.getCoin(), "BTC");
    EXPECT_EQ(sellTransaction.getCoin(), "ETH");
}

TEST_F(TransactionTest, GetQuantityReturnsCorrectValue) {
    EXPECT_EQ(buyTransaction.getQuantity(), 10);
    EXPECT_EQ(sellTransaction.getQuantity(), 5);
}

TEST_F(TransactionTest, GetPricePerCoinReturnsCorrectValue) {
    EXPECT_DOUBLE_EQ(buyTransaction.getPricePerCoin(), 50000.0);
    EXPECT_DOUBLE_EQ(sellTransaction.getPricePerCoin(), 2500.0);
}

TEST_F(TransactionTest, GetTypeReturnsCorrectValue) {
    EXPECT_EQ(buyTransaction.getType(), TransactionType::BUY);
    EXPECT_EQ(sellTransaction.getType(), TransactionType::SELL);
}

TEST_F(TransactionTest, PrintDoesNotThrow) {
    EXPECT_NO_THROW(buyTransaction.print());
    EXPECT_NO_THROW(sellTransaction.print());
}
