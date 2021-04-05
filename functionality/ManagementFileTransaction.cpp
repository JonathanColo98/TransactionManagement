//
// Created by colom on 05/04/2021.
//

#include "ManagementFileTransaction.h"

#include <utility>

ManagementFileTransaction::ManagementFileTransaction(Transaction transaction) : transaction(std::move(transaction)) {}

bool ManagementFileTransaction::writeToFileTransaction(std::ofstream &fileOutTransaction) {
    fileOutTransaction.open("transaction.txt", std::ios_base::out | std::ios_base::trunc);

    if(fileOutTransaction.is_open()) {
        fileOutTransaction << transaction;
        fileOutTransaction.close();
        return true;
    } else {
        return false;
    }
}

bool ManagementFileTransaction::readFromFileTransaction(std::ifstream &fileInTransaction) {
    fileInTransaction.open("transaction.txt", std::ios_base::in);

    if(fileInTransaction.good()) {
        fileInTransaction >> transaction;
        fileInTransaction.close();
        return true;
    } else {
        return false;
    }

}
