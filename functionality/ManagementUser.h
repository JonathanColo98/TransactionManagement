
#ifndef TRANSACTIONMANAGEMENT_MANAGEMENTUSER_H
#define TRANSACTIONMANAGEMENT_MANAGEMENTUSER_H

#include "../entities/User.h"
#include <fstream>

class ManagementUser {
private:
    User user;
    std::ofstream writeFileUser;
    std::ifstream readFileUser;

public:
    ManagementUser(const User &user, std::ofstream writeFileUser, std::ifstream readFileUser);
    User getUser() const;
    bool openWriteToFile();
    bool openReadToFile(std::ifstream readToFile);
    bool writeToFileUser(std::ofstream, User user);
    bool readFromFileUser(std::ifstream, std::string textFromFile);
};


#endif //TRANSACTIONMANAGEMENT_MANAGEMENTUSER_H
