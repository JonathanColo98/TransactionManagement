
#ifndef TRANSACTIONMANAGEMENT_MANAGEMENTFILEBANKACCOUNT_H
#define TRANSACTIONMANAGEMENT_MANAGEMENTFILEBANKACCOUNT_H

#include "../entities/BankAccount.h"

class ManagementFileBankAccount {

private:
    BankAccount bankAccount;

public:

    explicit ManagementFileBankAccount(BankAccount bankAccount);

    bool withdraw(const Transaction& transaction);

    bool deposit(const Transaction& transaction);

    bool writeToFileBankAccount(std::ofstream &fileOutBankAccount);

    bool readFromFileBankAccount(std::ifstream &fileInBankAccount);

};


#endif //TRANSACTIONMANAGEMENT_MANAGEMENTFILEBANKACCOUNT_H
