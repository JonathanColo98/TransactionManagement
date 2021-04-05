//
// Created by colom on 05/04/2021.
//

#ifndef TRANSACTIONMANAGEMENT_MANAGEMENTFILETRANSACTION_H
#define TRANSACTIONMANAGEMENT_MANAGEMENTFILETRANSACTION_H

#include "../entities/Transaction.h"

class ManagementFileTransaction {

private:
    Transaction transaction;

public:

    explicit ManagementFileTransaction(Transaction transaction);

    bool writeToFileTransaction(std::ofstream &fileOutTransaction);

    bool readFromFileTransaction(std::ifstream &fileInTransaction);

};


#endif //TRANSACTIONMANAGEMENT_MANAGEMENTFILETRANSACTION_H
