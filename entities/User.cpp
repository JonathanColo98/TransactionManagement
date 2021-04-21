
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

std::string User::toString() {
    return "[Nominativo: " + nominative + " E-mail: " + email + " Numero di telefono: " +  telephoneNumber + "]";
}

bool User::writeToFileUser(std::ofstream &fileOutUser, const User& user) {
    fileOutUser.open("user.txt", std::ios_base::out | std::ios_base::trunc);

    if(fileOutUser.is_open()) {
        fileOutUser << user;
        fileOutUser.close();
        return true;
    } else {
        return false;
    }
}

User User::readFromFileUser(std::ifstream &fileInUser) {
    fileInUser.open("user.txt", std::ios_base::in);

    if(fileInUser.good()) {
        fileInUser >> nominative;
        fileInUser >> email;
        fileInUser >> telephoneNumber;
        User userReadFromFile = User(nominative,email,telephoneNumber);
        fileInUser.close();
        return userReadFromFile;
    } else {
        User userObjectEmpty("", "", "");
        return userObjectEmpty;
    }

}




