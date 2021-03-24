//
// Created by colom on 24/03/2021.
//

#ifndef TRANSACTIONMANAGEMENT_BANK_H
#define TRANSACTIONMANAGEMENT_BANK_H

#include <iostream>
#include "BankAccount.h"


class Bank {
private:
    std::string bankName;
    std::vector<BankAccount> listBankAccounts = {};

public:
    Bank(std::string bankName, std::vector<BankAccount> listBankAccounts);
    std::string getBankName() const;
    std::vector<BankAccount> getListBankAccounts() const;
    std::string toString();
};



#endif //TRANSACTIONMANAGEMENT_BANK_H