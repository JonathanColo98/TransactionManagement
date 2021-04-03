
#include "User.h"

#include <utility>

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

std::ostream &operator<<(std::ostream &out, const User &obj) {
    out << obj.nominative << "\n" << obj.email <<"\n"<< obj.telephoneNumber <<std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, const User &obj) {
    in >> obj;
    return in;
}

std::string User::toString() {
    return "[Nominativo: " + nominative + " E-mail: " + email + " Numero di telefono: " +  telephoneNumber + "]";
}



