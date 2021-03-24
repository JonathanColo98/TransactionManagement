//
// Created by colom on 24/03/2021.
//

#include "Transaction.h"
#include <iostream>

Transaction::Transaction(std::string id, double amount) {
    this -> id = id;
    this -> amount = amount;
}

std::string Transaction::getId() const {
    return !id.empty() ? id : "empty field";
}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::toString() {
    std::cout << "Id Transazione: "<< id << "Importo: " << amount << std::endl;
}
