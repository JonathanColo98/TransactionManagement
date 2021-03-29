//
// Created by colom on 24/03/2021.
//

#include <sstream>
#include "Bank.h"

Bank::Bank(std::string bankName, std::vector<BankAccount> listBankAccounts) {
    this -> bankName = bankName;
    this -> listBankAccounts = listBankAccounts;
}

std::string Bank::getBankName() const {
    return bankName;
}

std::vector<BankAccount> Bank::getListBankAccounts() const {
    return listBankAccounts;
}

std::string Bank::toString() {
    std::stringstream streamBankAccounts;

    streamBankAccounts << "[Nome Banca: " << bankName;

    for (BankAccount bankAccount : listBankAccounts) {
        streamBankAccounts << bankAccount.toString() << std::endl;
    }

    return streamBankAccounts.str() + "]";
}

