
#include "ManagementUser.h"
#include <sstream>

ManagementUser::ManagementUser(const User &user, std::ofstream &outFileUser, std::ifstream &fileInUser) : user(user)  {
    this -> user = user;
    this -> fileOutUser = dynamic_cast<std::basic_ofstream<char, std::char_traits<char>> &&>(outFileUser);
    this -> fileInUser = dynamic_cast<std::basic_ifstream<char, std::char_traits<char>> &&>(fileInUser);
}

bool ManagementUser::writeToFileUser() {
    fileOutUser.open("user-output.txt", std::ios_base::out | std::ios_base::trunc);
    if(fileOutUser.is_open()) {
        fileOutUser << user;
        fileOutUser.close();
        return true;
    } else {
        return false;
    }
}

bool ManagementUser::readFromFileUser() {
    fileInUser.open("user-input.txt", std::ios_base::in);
    if(fileInUser.is_open()) {
        while (fileInUser.good()) {
            fileInUser >> user;
        }
        fileInUser.close();
        return true;
    } else {
        return false;
    }
}

