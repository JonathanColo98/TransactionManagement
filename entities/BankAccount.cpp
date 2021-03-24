//
// Created by colom on 24/03/2021.
//

#include "BankAccount.h"

BankAccount::BankAccount(std::string id, User& userAccount, std::vector<Transaction> listTransactions, double balance) :user(userAccount) {
    this -> id = id;
    this -> user = user;
    this -> listTransactions = listTransactions;
    this -> balance = balance;
}

std::string BankAccount::getId() const {
    return !id.empty() ? id : "empty field";
}

User BankAccount::getUser() const {
    return user;
}

std::vector<Transaction> BankAccount::getListTransactions() {
    return listTransactions;
}



