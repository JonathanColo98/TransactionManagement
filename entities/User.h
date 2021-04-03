
#ifndef TRANSACTIONMANAGEMENT_USER_H
#define TRANSACTIONMANAGEMENT_USER_H

#include <string>
#include <iostream>
#include <fstream>

class User {

private:
    std::string nominative;
    std::string email;
    std::string telephoneNumber;

public:
    User(std::string nominative, std::string email, std::string telephoneNumber);

    const std::string &getNominative() const;

    const std::string &getEmail() const;

    const std::string &getTelephoneNumber() const;

    std::string toString();

    /*
     * Write the member variables to stream objects
     */
    friend std::ostream & operator << (std::ostream &out, const User & obj);

    /*
     * Read data from stream object and fill it in member variables
     */

    friend std::istream & operator >> (std::istream &in, const User &obj);
};


#endif //TRANSACTIONMANAGEMENT_USER_H

