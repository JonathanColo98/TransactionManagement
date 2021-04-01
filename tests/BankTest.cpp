#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../entities/Bank.h"

TEST(BankTest, ToStringBankTest) {
    std::vector<BankAccount> listBankAccountTest = {};
    Bank bankObjectTest("Intesa Banca", listBankAccountTest);
    ASSERT_THAT("[Nome Banca: Intesa Banca]",bankObjectTest.toString());
}

