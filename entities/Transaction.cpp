
#include <iostream>
#include "Transaction.h"

Transaction::Transaction(std::string id, double amount, std::tm date) {
    this -> id = id;
    this -> amount = amount;
    this -> date = date;
}

std::string Transaction::getId() const {
    return id;
}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getDate() {
    return std::to_string(date.tm_mon) + "/" + std::to_string(date.tm_mday)  + "/" + std::to_string(date.tm_year);
}

std::string Transaction::toString() {
    return "[Id Transazione: " + id + " Importo: " + std::to_string(amount) + " Data[Giorno/Mese/Anno]: "+ getDate() +"]" ;
}
