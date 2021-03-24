//
// Created by colom on 24/03/2021.
//

#include "BankAccount.h"
#include <sstream>
#include <iostream>

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

double BankAccount::getBalance() {
    return balance;
}

std::string BankAccount::toString() {
    std::stringstream listOperations;

    listOperations << "Id: " << id << " user" << user.toString() << " balance: " << balance << std::endl;
    for (Transaction transaction : listTransactions) {
        listOperations << transaction.toString() << std::endl;
    }

    return listOperations.str();
}

