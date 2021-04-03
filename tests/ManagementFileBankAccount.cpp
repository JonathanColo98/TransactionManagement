
#include <gtest/gtest.h>
#include "../functionality/ManagementFileBankAccount.h"

TEST(ManagementFileBankAccountTest, WriteToFileCorrect) {
    User userObjectTest("Nome Utente", "nome.utente@email.it", "3645645665");
    std::vector<Transaction> listTransactionsTest = {};
    BankAccount bankAccountObject("123", userObjectTest, listTransactionsTest, 1000.0);
    std::ofstream fileOutBankAccountTest;
    ManagementFileBankAccount managementFileBankAccountTest(bankAccountObject);
    ASSERT_TRUE(managementFileBankAccountTest.writeToFileBankAccount(fileOutBankAccountTest));
}

TEST(ManagementFileBankAccountTest, ReadToFileCorrect) {
    User userObjectTest("Nome Utente", "nome.utente@email.it", "3645645665");
    std::vector<Transaction> listTransactionsTest = {};
    BankAccount bankAccountObject("123", userObjectTest, listTransactionsTest, 1000.0);
    std::ifstream fileInBankAccountTest;
    ManagementFileBankAccount managementFileBankAccountTest(bankAccountObject);
    ASSERT_TRUE(managementFileBankAccountTest.readFromFileBankAccount(fileInBankAccountTest));
}