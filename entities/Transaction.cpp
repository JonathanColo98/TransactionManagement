//
// Created by colom on 24/03/2021.
//

#include "Transaction.h"
#include <iostream>

Transaction::Transaction(std::string id, double amount, std::tm date) {
    this -> id = id;
    this -> amount = amount;
    this -> date = date;
}

std::string Transaction::getId() const {
    return !id.empty() ? id : "empty field";
}

double Transaction::getAmount() const {
    return amount;
}

std::tm Transaction::getDate() {
    return date;
}

std::string Transaction::toString() {
    return "[Id Transazione: " + id + "Importo: " + std::to_string(amount) + " Data[Giorno: " +  std::to_string(date.tm_mday) + " Mese: " +  std::to_string(date.tm_mon)
    +  " Anno: " + std::to_string(date.tm_year) + "]]" ;
}
