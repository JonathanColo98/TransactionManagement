
#ifndef TRANSACTIONMANAGEMENT_TRANSACTION_H
#define TRANSACTIONMANAGEMENT_TRANSACTION_H

#include <ctime>
#include <iostream>
#include <fstream>

class Transaction {

private:
    std::string id;
    double amount;
    std::tm date;

public:
    Transaction(const std::string &id, double amount, const tm &date);

    const std::string &getId() const;

    double getAmount() const;

    const tm &getDate() const;

    friend bool operator == (const Transaction& leftUser, const Transaction& rightUser) {
        return leftUser.id == rightUser.id &&
               leftUser.amount == rightUser.amount &&
               leftUser.date.tm_mon == rightUser.date.tm_mon &&
               leftUser.date.tm_mday == leftUser.date.tm_year &&
               leftUser.date.tm_year == rightUser.date.tm_year;
    }

    /*
     * Write the member variables to stream objects
     */

    friend std::ostream & operator << (std::ostream &out, const Transaction & obj) {
        out << obj.id << "\n" << obj.amount <<"\n" << obj.getDateToString() <<std::endl;
        return out;
    }

    /*
     * Read data from stream object and fill it in member variables
     */

    friend std::istream & operator >> (std::istream &in, Transaction &obj) {
        in >> obj.id;
        in >> obj.date.tm_mon;
        in >> obj.date.tm_mday;
        in >> obj.date.tm_year;
        in >> obj.amount;
        return in;
    }

    std::string Transaction::getDateToString() const;

    std::string toString();

    bool writeToFileTransaction(std::ofstream &fileOutTransaction, const Transaction &transaction);

    Transaction readFromFileTransaction(std::ifstream &fileInTransaction);

};


#endif //TRANSACTIONMANAGEMENT_TRANSACTION_H
