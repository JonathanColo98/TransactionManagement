
#include "BankAccount.h"
#include <sstream>
#include <iostream>
#include <utility>

BankAccount::BankAccount(std::string id, User userAccount, std::vector<Transaction> listTransactions, double balance) :user(std::move(userAccount)) {
    this -> id = std::move(id);
    this -> user = userAccount;
    this -> listTransactions = std::move(listTransactions);
    this -> balance = balance;
}

std::string BankAccount::getId() const {
    return id;
}

User BankAccount::getUser() const {
    return user;
}

std::vector<Transaction> BankAccount::getListTransactions() {
    return listTransactions;
}

double BankAccount::getBalance() const {
    return balance;
}

bool BankAccount::setBalance(double newBalance) {
    if(newBalance < 0) {
        return false;
    } else {
        this -> balance = newBalance;
        return true;
    }
}

bool BankAccount::addTransaction(Transaction transaction) {
    listTransactions.push_back(transaction);
    return true;
}

std::string BankAccount::toString() {
    std::stringstream listOperations;

    listOperations << "[Id: " << id << " Utente:" << user.toString() << " Saldo: " << balance << std::endl;
    for (Transaction transaction : listTransactions) {
        listOperations << transaction.toString() << std::endl;
    }

    return listOperations.str() + "]";
}

