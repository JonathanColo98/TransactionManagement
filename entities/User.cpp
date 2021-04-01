
#include "User.h"

User::User(std::string nominative, std::string email, std::string telephoneNumber) {
    this -> nominative = std::move(nominative);
    this -> email = std::move(email);
    this -> telephoneNumber = std::move(telephoneNumber);
}

std::string User::getNominative() const {
    return nominative;
}

std::string User::getEmail() const {
    return email;
}

std::string User::getTelephoneNumber() const {
    return telephoneNumber;
}

std::string User::toString() {
    return "[Nominativo: " + nominative + " E-mail: " + email + " Numero di telefono: " +  telephoneNumber + "]";
}


