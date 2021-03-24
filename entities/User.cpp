//
// Created by colom on 24/03/2021.
//

#include "User.h"
#include <iostream>

User::User(std::string nominative, std::string email, std::string telephoneNumber) {
    this -> nominative = nominative;
    this -> email = email;
    this -> telephoneNumber = telephoneNumber;
}

std::string User::getNominative() const {
     !nominative.empty() ? nominative : "empty field";
}

std::string User::getEmail() const {
    !email.empty() ? email : "empty field";
}

std::string User::getTelephoneNumber() const {
    !telephoneNumber.empty() ? email : "empty field";
}

std::string User::toString() {
    std::cout << "Nominativo: "<< nominative << "E-mail: " << email << "Numero di telefono: " << telephoneNumber << std::endl;
}


