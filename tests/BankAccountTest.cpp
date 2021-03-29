
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../entities/BankAccount.h"

TEST(BankAccountTest, ToStringBankAccountTest) {
    User userObjectTest("Nome Utente", "nome.utente@email.it", "3645645665");
    std::vector<Transaction> listTransactionsTest = {};
    BankAccount bankAccountObject("123", userObjectTest, listTransactionsTest, 1000.0);
    ASSERT_THAT("[Id: 123 Utente:[Nominativo: Nome Utente E-mail: nome.utente@email.it Numero di telefono: 3645645665] Saldo: 1000]\n",
                bankAccountObject.toString());
}