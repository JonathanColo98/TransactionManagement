
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

    friend std::ostream & operator << (std::ostream &out, const BankAccount & obj) {
        out << obj.id << "\n" << obj.user << "\n" << obj.getListTransactionsToString() << "\n" << obj.balance << std::endl;
        return out;
    }

    /*
     * Read data from stream object and fill it in member variables
     */

    friend std::istream & operator >> (std::istream &in, BankAccount &obj) {
        in >> obj.id;
        in >> obj.user;
        in >> obj.balance;

        std::vector<Transaction> data;
        struct tm nowlocal;

        Transaction element("",0,nowlocal);

        while (in >> element) {
            data.push_back(element);
        }
        
        return in;
    }

    bool addTransaction(const Transaction& transaction);

    bool BankAccount::setNewBalance(double newBalance);

    std::string toString();

};


#endif //TRANSACTIONMANAGEMENT_BANKACCOUNT_H
