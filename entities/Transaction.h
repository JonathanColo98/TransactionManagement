
#ifndef TRANSACTIONMANAGEMENT_TRANSACTION_H
#define TRANSACTIONMANAGEMENT_TRANSACTION_H

#include <string>
#include <ctime>

class Transaction {
private:
    std::string id;
    double amount = 0;
    std::tm date;

public:
    Transaction(std::string id, double amount, std::tm date);
    std::string getId() const;
    double getAmount() const;
    std::string getDate() const;
    std::string toString() ;
};


#endif //TRANSACTIONMANAGEMENT_TRANSACTION_H
