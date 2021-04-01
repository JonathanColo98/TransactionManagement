
#include "ManagementFileBankAccount.h"
#include <iostream>
#include <string>
#include <sstream>

ManagementFileBankAccount::ManagementFileBankAccount(const BankAccount &bankAccount, std::ofstream &writeToFile,
                                                     std::ifstream &readFromFile) : bankAccount(bankAccount) {
    this -> bankAccount = bankAccount;
    this -> writeToFile = dynamic_cast<std::basic_ofstream<char, std::char_traits<char>> &&>(writeToFile);
    this -> readFromFile = dynamic_cast<std::basic_ifstream<char, std::char_traits<char>> &&>(readFromFile);
}

bool ManagementFileBankAccount::withdraw(const Transaction& transaction) {
    if (bankAccount.getBalance() < transaction.getAmount()) {
        std::cout << "Balance minor of amount";
        return false;
    } else {
        bankAccount.setBalance(bankAccount.getBalance() - transaction.getAmount());
        return true;
    }
}

bool ManagementFileBankAccount::deposit(const Transaction& transaction) {
    if(transaction.getAmount() <= 0) {
        std::cout << "Impossible deposit this amount";
        return false;
    } else {
        bankAccount.setBalance(bankAccount.getBalance() + transaction.getAmount());
        return true;
    }
}

bool ManagementFileBankAccount::writeToFileBankAccount() {
    writeToFile.open("BankAccount.txt", std::ios_base::out | std::ios_base::trunc);
    if(writeToFile.is_open()) {
        writeToFile << "Information Bank Account\n";
        writeToFile << bankAccount.toString();
        writeToFile.close();
        return true;
    } else {
        return false;
    }
}

bool ManagementFileBankAccount::readFromFileBankAccount(std::string textFromFile) {
    readFromFile.open("BankAccount.txt", std::ios_base::in);

    if (readFromFile.is_open()) {
        while (readFromFile.good()) {
            std::getline(readFromFile, textFromFile);
            std::vector<std::string> vectorWords = StringToVector(textFromFile, '\n');
        }
        readFromFile.close();
        return true;
    } else {
        return false;
    }

}

std::vector<std::string> ManagementFileBankAccount::StringToVector(std::string theString, char separator) {

    //Create a vector
    std::vector<std::string> vectorWords;

    // A stringstream object receives strings separated
    // by a space and then spits the out 1 by 1
    std::stringstream streamOfStrings(theString);

    // Will temporarily hold each word in the string
    std::string stringWord;

    // While there are more words to extract keep executing
    // getline takes strings from a stream of words stored in the
    // stream and each time it finds a blanks space
    // it stores the word proceeding the space in sIndivStr
    while (std::getline(streamOfStrings, stringWord, separator)) {
        // Put the string into a vector
        vectorWords.push_back(stringWord);
    }

    return vectorWords;
}

