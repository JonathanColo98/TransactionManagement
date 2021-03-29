//
// Created by colom on 24/03/2021.
//

#include <iostream>
#include "User.h"

User::User(std::string nominative, std::string email, std::string telephoneNumber) {
    this -> nominative = nominative;
    this -> email = email;
    this -> telephoneNumber = telephoneNumber;
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


