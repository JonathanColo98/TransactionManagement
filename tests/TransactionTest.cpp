
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../entities/Transaction.h"

TEST(TransactionTest, ToStringTransactioTest) {
    struct tm nowlocal;
    nowlocal.tm_mon = 28;
    nowlocal.tm_mday = 3;
    nowlocal.tm_year = 2021;
    Transaction transactionObject("1", 1000.0, nowlocal);
    ASSERT_THAT("[Id Transazione: 1 Importo: 1000.000000 Data[Giorno/Mese/Anno]: 28/3/2021]", transactionObject.toString());
}