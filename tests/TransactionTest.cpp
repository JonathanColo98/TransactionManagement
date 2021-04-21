
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../entities/Transaction.h"

TEST(TransactionTest, ToStringTransactionTest) {
    struct tm nowlocal;
    nowlocal.tm_mon = 28;
    nowlocal.tm_mday = 3;
    nowlocal.tm_year = 2021;
    Transaction transactionObject("1", 1000.0, nowlocal);
    ASSERT_THAT("[Id Transazione: 1 Importo: 1000.000000 Data[Giorno/Mese/Anno]: 28/3/2021]", transactionObject.toString());
}

TEST(TransactionTest, WriteToFileCorrectly) {

    struct tm nowlocal;
    nowlocal.tm_mon = 28;
    nowlocal.tm_mday = 3;
    nowlocal.tm_year = 2021;
    Transaction transactionObject("1", 1000.0, nowlocal);

    std::ofstream fileOutTransactionTest;

    ASSERT_TRUE(transactionObject.writeToFileTransaction(fileOutTransactionTest, transactionObject));
}

// test da fare
TEST(TransactionTest, ReadToFileCorrectly) {

}

/*
TEST(ManagementTransactionTest, ReadToFileCorrectly) {
    struct tm nowlocal;
    nowlocal.tm_mon = 28;
    nowlocal.tm_mday = 3;
    nowlocal.tm_year = 2021;
    Transaction transactionObject("1", 1000.0, nowlocal);

    std::ofstream fileOutTransactionTest;
    std::ifstream fileInTransactionTest;
    ManagementFileTransaction managementTransactionTest(transactionObject);

    fileOutTransactionTest.open("transaction.txt", std::ios_base::out | std::ios_base::trunc);

    if(fileOutTransactionTest.is_open()) {
        fileOutTransactionTest << transactionObject;
        fileOutTransactionTest.close();
    }

    ASSERT_TRUE(managementTransactionTest.readFromFileTransaction(fileInTransactionTest));
}
*/