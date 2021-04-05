
#include "User.h"

User::User(std::string nominative, std::string email, std::string telephoneNumber) : nominative(std::move(
        nominative)), email(std::move(email)), telephoneNumber(std::move(telephoneNumber)) {}

const std::string &User::getNominative() const {
    return nominative;
}

const std::string &User::getEmail() const {
    return email;
}

const std::string &User::getTelephoneNumber() const {
    return telephoneNumber;
}

std::string User::toString() {
    return "[Nominativo: " + nominative + " E-mail: " + email + " Numero di telefono: " +  telephoneNumber + "]";
}



