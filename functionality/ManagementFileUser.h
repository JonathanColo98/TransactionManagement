
#ifndef TRANSACTIONMANAGEMENT_MANAGEMENTFILEUSER_H
#define TRANSACTIONMANAGEMENT_MANAGEMENTFILEUSER_H

#include "../entities/User.h"

class ManagementFileUser {

private:
    User user;

public:
    explicit ManagementFileUser(User user);

    bool writeToFileUser(std::ofstream &fileOutUser);

    bool readFromFileUser(std::ifstream &fileInUser);

};


#endif //TRANSACTIONMANAGEMENT_MANAGEMENTFILEUSER_H
