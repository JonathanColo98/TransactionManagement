
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../entities/BankAccount.h"

TEST(BankAccountTest, ToStringBankAccountTest) {
    User userObjectTest("Nome Utente", "nome.utente@email.it", "3645645665");
    std::vector<Transaction> listTransactionsTest = {};
    BankAccount bankAccountObject("123", userObjectTest, listTransactionsTest, 1000.0);
    ASSERT_THAT("[Id: 123 Utente:[Nominativo: Nome Utente E-mail: nome.utente@email.it Numero di telefono: 3645645665] Saldo: 1000\n]",
                bankAccountObject.toString());
}

TEST(BankAccountTest, AddCorrectTransactionToList) {
    User userObjectTest("Nome Utente", "nome.utente@email.it", "3645645665");
    std::vector<Transaction> listTransactionsTest = {};
    BankAccount bankAccountObject("123", userObjectTest, listTransactionsTest, 1000.0);
    struct tm nowlocal;
    nowlocal.tm_mon = 28;
    nowlocal.tm_mday = 3;
    nowlocal.tm_year = 2021;
    Transaction transactionObject("1", 1000.0, nowlocal);
    ASSERT_TRUE(bankAccountObject.addTransaction(transactionObject));
}

TEST(UserTest, SetNewBalanceFalse) {
    User userObjectTest("Nome Utente", "nome.utente@email.it", "3645645665");
    std::vector<Transaction> listTransactionsTest = {};
    BankAccount bankAccountObject("123", userObjectTest, listTransactionsTest, 1000.0);
    struct tm nowlocal;
    nowlocal.tm_mon = 28;
    nowlocal.tm_mday = 3;
    nowlocal.tm_year = 2021;
    Transaction transactionObject("1", -1, nowlocal);
    ASSERT_FALSE(bankAccountObject.setNewBalance(transactionObject.getAmount()));
}

TEST(UserTest, SetNewBalanceTrue) {
    User userObjectTest("Nome Utente", "nome.utente@email.it", "3645645665");
    std::vector<Transaction> listTransactionsTest = {};
    BankAccount bankAccountObject("123", userObjectTest, listTransactionsTest, 1000.0);
    struct tm nowlocal;
    nowlocal.tm_mon = 28;
    nowlocal.tm_mday = 3;
    nowlocal.tm_year = 2021;
    Transaction transactionObject("1", 5000, nowlocal);
    ASSERT_TRUE(bankAccountObject.setNewBalance(transactionObject.getAmount()));
}
