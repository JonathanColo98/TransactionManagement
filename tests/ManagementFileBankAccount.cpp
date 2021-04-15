
#include <gtest/gtest.h>
#include "../functionality/ManagementFileBankAccount.h"

TEST(ManagementFileBankAccountTest, WriteToFileCorrectly) {
    User userObjectTest("Nome Utente", "nome.utente@email.it", "3645645665");
    std::list<Transaction> listTransactionsTest = {};
    BankAccount bankAccountObject("123", userObjectTest, listTransactionsTest, 1000.0);
    std::ofstream fileOutBankAccountTest;
    struct tm nowlocal;
    nowlocal.tm_mon = 28;
    nowlocal.tm_mday = 3;
    nowlocal.tm_year = 2021;
    Transaction transactionObject("1", 1000.0, nowlocal);
    bankAccountObject.addTransaction(transactionObject);
    ManagementFileBankAccount managementFileBankAccountTest(bankAccountObject);
    ASSERT_TRUE(managementFileBankAccountTest.writeToFileBankAccount(fileOutBankAccountTest));
}

TEST(ManagementFileBankAccountTest, ReadToFileCorrectly) {
    User userObjectTest("Nome Utente", "nome.utente@email.it", "3645645665");
    std::list<Transaction> listTransactionsTest = {};
    BankAccount bankAccountObject("123", userObjectTest, listTransactionsTest, 1000.0);
    std::ifstream fileInBankAccountTest;
    std::ofstream fileOutBankAccountTest;
    ManagementFileBankAccount managementFileBankAccountTest(bankAccountObject);
    struct tm nowlocal;
    nowlocal.tm_mon = 28;
    nowlocal.tm_mday = 3;
    nowlocal.tm_year = 2021;
    Transaction transactionObject("1", 1000.0, nowlocal);
    bankAccountObject.addTransaction(transactionObject);
    fileOutBankAccountTest.open("bank-account.txt", std::ios_base::out | std::ios_base::trunc);

    if(fileOutBankAccountTest.is_open()) {
        fileOutBankAccountTest << bankAccountObject;
        fileOutBankAccountTest.close();
    }

    ASSERT_TRUE(managementFileBankAccountTest.readFromFileBankAccount(fileInBankAccountTest));
}

TEST(ManagementFileBankAccountTest, WithdrawTransactionTestTrue) {
    User userObjectTest("Nome Utente", "nome.utente@email.it", "3645645665");
    std::list<Transaction> listTransactionsTest = {};
    BankAccount bankAccountObject("123", userObjectTest, listTransactionsTest, 1000.0);
    ManagementFileBankAccount managementFileBankAccountTest(bankAccountObject);
    struct tm nowlocal;
    nowlocal.tm_mon = 28;
    nowlocal.tm_mday = 3;
    nowlocal.tm_year = 2021;
    Transaction transactionObject("4", 500.0, nowlocal);
    ASSERT_TRUE(managementFileBankAccountTest.withdraw(transactionObject));
}

TEST(ManagementFileBankAccountTest, WithdrawTransactionTestFalse) {
    User userObjectTest("Nome Utente", "nome.utente@email.it", "3645645665");
    std::list<Transaction> listTransactionsTest = {};
    BankAccount bankAccountObject("123", userObjectTest, listTransactionsTest, 1000.0);
    ManagementFileBankAccount managementFileBankAccountTest(bankAccountObject);
    struct tm nowlocal;
    nowlocal.tm_mon = 28;
    nowlocal.tm_mday = 3;
    nowlocal.tm_year = 2021;
    Transaction transactionObject("4", 0, nowlocal);
    ASSERT_FALSE(managementFileBankAccountTest.withdraw(transactionObject));
    Transaction transactionObject2("4", -1, nowlocal);
    ASSERT_FALSE(managementFileBankAccountTest.withdraw(transactionObject2));
}

TEST(ManagementFileBankAccountTest, DepositTransactionTestTrue) {
    User userObjectTest("Nome Utente", "nome.utente@email.it", "3645645665");
    std::list<Transaction> listTransactionsTest = {};
    BankAccount bankAccountObject("123", userObjectTest, listTransactionsTest, 1000.0);
    ManagementFileBankAccount managementFileBankAccountTest(bankAccountObject);
    struct tm nowlocal;
    nowlocal.tm_mon = 28;
    nowlocal.tm_mday = 3;
    nowlocal.tm_year = 2021;
    Transaction transactionObject("4", 1000, nowlocal);
    ASSERT_TRUE(managementFileBankAccountTest.deposit(transactionObject));
}

TEST(ManagementFileBankAccountTest, DepositTransactionTestFalse) {
    User userObjectTest("Nome Utente", "nome.utente@email.it", "3645645665");
    std::list<Transaction> listTransactionsTest = {};
    BankAccount bankAccountObject("123", userObjectTest, listTransactionsTest, 1000.0);
    ManagementFileBankAccount managementFileBankAccountTest(bankAccountObject);
    struct tm nowlocal;
    nowlocal.tm_mon = 28;
    nowlocal.tm_mday = 3;
    nowlocal.tm_year = 2021;
    Transaction transactionObject("4", 0, nowlocal);
    ASSERT_FALSE(managementFileBankAccountTest.deposit(transactionObject));
    Transaction transactionObject2("4", -1, nowlocal);
    ASSERT_FALSE(managementFileBankAccountTest.deposit(transactionObject2));
}