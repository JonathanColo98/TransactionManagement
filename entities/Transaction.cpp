
#include "Transaction.h"
#include <string>

Transaction::Transaction(const std::string &id, double amount, const tm &date) : id(id), amount(amount), date(date) {}

const std::string &Transaction::getId() const {
    return id;
}

double Transaction::getAmount() const {
    return amount;
}

const tm &Transaction::getDate() const {
    return date;
}

std::string Transaction::getDateToString() const {
    return std::to_string(date.tm_mon) + "/" + std::to_string(date.tm_mday)  + "/" + std::to_string(date.tm_year);
}

std::string Transaction::toString() {
    return "[Id Transazione: " + id + " Importo: " + std::to_string(amount) + " Data[Giorno/Mese/Anno]: "+ getDateToString() +"]";
}

bool Transaction::writeToFileTransaction(std::ofstream &fileOutTransaction, const Transaction& transaction) {
    fileOutTransaction.open("transaction.txt", std::ios_base::out | std::ios_base::trunc);

    if(fileOutTransaction.is_open()) {
        fileOutTransaction << transaction;
        fileOutTransaction.close();
        return true;
    } else {
        return false;
    }
}

Transaction Transaction::readFromFileTransaction(std::ifstream &fileInTransaction) {
    fileInTransaction.open("transaction.txt", std::ios_base::in);

    if(fileInTransaction.good()) {
        fileInTransaction >> id;
        fileInTransaction >> amount;
        fileInTransaction >> date.tm_mon;
        fileInTransaction >> date.tm_mday;
        fileInTransaction >> date.tm_year;
        fileInTransaction.close();
        struct tm nowlocal;
        nowlocal.tm_mon = date.tm_mon;
        nowlocal.tm_mday = date.tm_mday;
        nowlocal.tm_year = date.tm_year;
        Transaction transaction(id, amount, nowlocal);
        return transaction;
    } else {
        struct tm nowlocal;
        Transaction transaction("",0,nowlocal);
        return transaction;
    }

}



