
#ifndef TRANSACTIONMANAGEMENT_MANAGEMENTFILEBANKACCOUNT_H
#define TRANSACTIONMANAGEMENT_MANAGEMENTFILEBANKACCOUNT_H

#include "../entities/BankAccount.h"
#include <fstream>
#include <istream>

class ManagementFileBankAccount {
private:
    BankAccount bankAccount;
    std::ofstream writeToFile;
    std::ifstream readFromFile;

public:
    ManagementFileBankAccount(const BankAccount &bankAccount, std::ofstream &writeToFile, std::ifstream &readFromFile);
    bool withdraw(const Transaction& transaction);
    bool deposit(const Transaction& transaction);

    bool writeToFileBankAccount();
    bool readFromFileBankAccount(std::string textFromFile);

private:
    std::vector<std::string> StringToVector(std::string theString , char separator);
};


#endif //TRANSACTIONMANAGEMENT_MANAGEMENTFILEBANKACCOUNT_H
