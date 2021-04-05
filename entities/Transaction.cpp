
#include "Transaction.h"
#include <string>


Transaction::Transaction(std::string id, double amount, const tm &date) : id(std::move(id)), amount(amount), date(date) {}

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

