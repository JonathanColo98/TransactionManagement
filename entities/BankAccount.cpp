
#include "BankAccount.h"
#include <sstream>
#include <utility>

BankAccount::BankAccount(std::string id, User user, std::vector<Transaction> listTransactions,
                         double balance) : id(std::move(id)), user(std::move(user)), listTransactions(std::move(listTransactions)), balance(balance) {}

const std::string &BankAccount::getId() const {
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

std::ostream &operator<<(std::ostream &out, const BankAccount &obj) {
    out << obj.id << "\n" << obj.user << "\n" << obj.getListTransactionsToString() << "\n" << obj.balance  << std::endl;
    return out;
}

std::string BankAccount::getListTransactionsToString() const {
    std::stringstream listOperations;

    for (Transaction transaction : listTransactions) {
        listOperations << transaction.toString() << std::endl;
    }

    return listOperations.str();
}

std::istream &operator>>(std::istream &in, const BankAccount &obj) {
    in >> obj;
    return in;
}

bool BankAccount::addTransaction(const Transaction& transaction) {
    listTransactions.push_back(transaction);
    return true;
}

bool BankAccount::setNewBalance(double newBalance) {
    if(newBalance < 0) {
        return false;
    } else {
        BankAccount::balance = newBalance;
        return true;
    }
}

std::string BankAccount::toString() {
    std::stringstream listOperations;

    listOperations << "[Id: " << id << " Utente:" << user.toString() << " Saldo: " << balance << std::endl;
    for (Transaction transaction : listTransactions) {
        listOperations << transaction.toString() << std::endl;
    }

    return listOperations.str() + "]";
}



