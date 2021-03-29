#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../entities/Bank.h"

TEST(BankTest, ToStringBankTest) {
    //Bank bankObjectTest("Nome banca", "name.user@email.it", "3645645665");
    std::vector<BankAccount> listBankAccountTest = {};
    Bank bankObjectTest("Intesa Banca", listBankAccountTest);
    ASSERT_THAT("[Nome Banca: Intesa Banca]",bankObjectTest.toString());
}

