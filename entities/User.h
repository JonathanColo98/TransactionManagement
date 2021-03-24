//
// Created by colom on 24/03/2021.
//

#ifndef TRANSACTIONMANAGEMENT_USER_H
#define TRANSACTIONMANAGEMENT_USER_H

#include <string>

class User {
private:
    std::string nominative;
    std::string email;
    std::string telephoneNumber;

public:
    User(std::string nominative, std::string email, std::string telephoneNumber);
    std::string getNominative() const;
    std::string getEmail() const;
    std::string getTelephoneNumber() const;
    std::string toString();
};


#endif //TRANSACTIONMANAGEMENT_USER_H
