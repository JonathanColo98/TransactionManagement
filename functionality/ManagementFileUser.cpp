
#include "ManagementFileUser.h"
#include <sstream>
#include <utility>

ManagementFileUser::ManagementFileUser(User user) : user(std::move(user)) {}

bool ManagementFileUser::writeToFileUser(std::ofstream &fileOutUser) {
    fileOutUser.open("user.txt", std::ios_base::out | std::ios_base::trunc);

    if(fileOutUser.is_open()) {
        fileOutUser << user;
        fileOutUser.close();
        return true;
    } else {
        return false;
    }
}

bool ManagementFileUser::readFromFileUser(std::ifstream &fileInUser) {
    fileInUser.open("user.txt", std::ios_base::in);

    if(fileInUser.good()) {
        fileInUser >> user;
        fileInUser.close();
        return true;
    } else {
        return false;
    }

}



