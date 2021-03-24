//
// Created by colom on 24/03/2021.
//

#ifndef TRANSACTIONMANAGEMENT_TRANSACTION_H
#define TRANSACTIONMANAGEMENT_TRANSACTION_H

#include <string>

class Transaction {
private:
    std::string id;
    double amount = 0;

public:
    Transaction(std::string id, double amount);
    std::string getId() const;
    double getAmount() const;
    std::string toString();
};


#endif //TRANSACTIONMANAGEMENT_TRANSACTION_H
