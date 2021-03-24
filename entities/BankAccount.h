//
// Created by colom on 24/03/2021.
//

#ifndef TRANSACTIONMANAGEMENT_BANKACCOUNT_H
#define TRANSACTIONMANAGEMENT_BANKACCOUNT_H

#include <vector>
#include "Transaction.h"
#include "User.h"

class BankAccount {
private:
    std::string id;
    User user;
    std::vector<Transaction> listTransactions = {};
    double balance;

public:
    BankAccount(std::string id, User &userAccount, std::vector<Transaction> listTransactions, double balance);
    std::string getId() const;
    User getUser() const;
    std::vector<Transaction> getListTransactions();
    //double getBalance();
    //std::string toString();
};


#endif //TRANSACTIONMANAGEMENT_BANKACCOUNT_H
