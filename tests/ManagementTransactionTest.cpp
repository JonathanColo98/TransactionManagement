
#include <gtest/gtest.h>
#include "../functionality/ManagementFileTransaction.h"

TEST(ManagementTransactionTest, WriteToFileCorrectly) {

    struct tm nowlocal;
    nowlocal.tm_mon = 28;
    nowlocal.tm_mday = 3;
    nowlocal.tm_year = 2021;
    Transaction transactionObject("1", 1000.0, nowlocal);

    std::ofstream fileOutTransactionTest;

    ManagementFileTransaction managementTransactionTest(transactionObject);
    ASSERT_TRUE(managementTransactionTest.writeToFileTransaction(fileOutTransactionTest));
}

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

