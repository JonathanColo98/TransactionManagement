
#include <gtest/gtest.h>
#include "../functionality/ManagementFileBankAccount.h"

TEST(ManagementBankAccountTest, TestWriteToFile) {
    User userTest("Nome Utente", "nome.utente@email.it", "3645645665");
    std::vector<Transaction> listTransactionsTest = {};
    BankAccount bankAccountTest("123", userTest, listTransactionsTest, 1000.0);
    std::ofstream writeToFile;
    std::ifstream readFromFile;
    ManagementFileBankAccount managementFileBankAccountTest(bankAccountTest, writeToFile, readFromFile);
    ASSERT_TRUE(managementFileBankAccountTest.writeToFileBankAccount());
}

TEST(ManagementBankAccountTest, TestReadFromFile) {
    User userTest("Nome Utente", "nome.utente@email.it", "3645645665");
    std::vector<Transaction> listTransactionsTest = {};
    BankAccount bankAccountTest("123", userTest, listTransactionsTest, 1000.0);
    std::ofstream writeToFileTest;
    std::ifstream readFromFileTest;
    std::string textFromFileTest;
    ManagementFileBankAccount managementFileBankAccountTest(bankAccountTest, writeToFileTest, readFromFileTest);
    ASSERT_TRUE(managementFileBankAccountTest.readFromFileBankAccount(textFromFileTest));
}
