
#ifndef TRANSACTIONMANAGEMENT_BANKACCOUNT_H
#define TRANSACTIONMANAGEMENT_BANKACCOUNT_H

#include "User.h"
#include "Transaction.h"
#include <vector>

class BankAccount {

private:
    std::string id;
    User user;
    std::vector<Transaction> listTransactions = {};
    double balance;

public:
    BankAccount(std::string id, User user, std::vector<Transaction> listTransactions,
                double balance);

    const std::string &getId() const;

    User getUser() const;

    std::vector<Transaction> getListTransactions();

    double getBalance() const;

    std::string BankAccount::getListTransactionsToString() const;

    /*
    * Write the member variables to stream objects
    */

    friend std::ostream & operator << (std::ostream &out, const BankAccount & obj);

    /*
     * Read data from stream object and fill it in member variables
     */

    friend std::istream & operator >> (std::istream &in, const BankAccount &obj);

    bool addTransaction(const Transaction& transaction);

    bool BankAccount::setNewBalance(double newBalance);

    std::string toString();

};


#endif //TRANSACTIONMANAGEMENT_BANKACCOUNT_H
