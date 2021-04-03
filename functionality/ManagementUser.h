
#ifndef TRANSACTIONMANAGEMENT_MANAGEMENTUSER_H
#define TRANSACTIONMANAGEMENT_MANAGEMENTUSER_H

#include "../entities/User.h"

class ManagementUser {

private:
    User user;
    std::ofstream fileOutUser;
    std::ifstream fileInUser;

public:
    ManagementUser(const User &user, std::ofstream &outFileUser, std::ifstream &fileInUser);

    bool writeToFileUser();

    bool readFromFileUser();

};


#endif //TRANSACTIONMANAGEMENT_MANAGEMENTUSER_H
