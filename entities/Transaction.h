
#ifndef TRANSACTIONMANAGEMENT_TRANSACTION_H
#define TRANSACTIONMANAGEMENT_TRANSACTION_H

#include <string>
#include <ctime>

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

    /*
     * Write the member variables to stream objects
     */

    friend std::ostream & operator << (std::ostream &out, const Transaction & obj);

    /*
     * Read data from stream object and fill it in member variables
     */

    friend std::istream & operator >> (std::istream &in, const Transaction &obj);

    std::string Transaction::getDateToString() const;

    std::string toString();

};


#endif //TRANSACTIONMANAGEMENT_TRANSACTION_H
