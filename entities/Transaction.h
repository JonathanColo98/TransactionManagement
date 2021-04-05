
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
    Transaction(std::string id, double amount, const tm &date);

    const std::string &getId() const;

    double getAmount() const;

    const tm &getDate() const;

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

    std::string getDateToString() const;

    std::string toString();

};


#endif //TRANSACTIONMANAGEMENT_TRANSACTION_H
