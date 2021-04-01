
#include "ManagementUser.h"
#include <iostream>

ManagementUser::ManagementUser(const User &user, std::ofstream writeFileUser, std::ifstream readFileUser) :user(user)  {
    this -> user = user;
    this -> writeFileUser = dynamic_cast<std::basic_ofstream<char, std::char_traits<char>> &&>(writeFileUser);
    this -> readFileUser = dynamic_cast<std::basic_ifstream<char, std::char_traits<char>> &&>(readFileUser);
}

bool ManagementUser::openWriteToFile() {
    writeFileUser.open("WriteUser.txt", std::ios_base::out | std::ios_base::trunc);
    if (writeFileUser.is_open()) {
        return true;
    } else {
        return false;
    }
}

bool ManagementUser::openReadToFile(std::ifstream readToFile) {
    readToFile.open("ReadUser.txt", std::ios_base::in);
    if (readToFile.is_open()) {
        return true;
    } else {
        return false;
    }
}

bool ManagementUser::writeToFileUser(std::ofstream writeToFile, User user) {
    if(writeToFile.is_open()) {
        writeToFile << "Information User" << std::endl;
        writeToFile << user.toString();
        writeToFile.close();
        return true;
    } else {
        return false;
    }
}

bool ManagementUser::readFromFileUser(std::ifstream readToFile, std::string textFromFile) {
    if(readToFile.is_open()) {
        while (readToFile.good()) {
            std::getline(readToFile, textFromFile);
            std::cout << textFromFile << std::endl;
        }
        readToFile.close();
        return true;
    } else {
        return false;
    }
}
