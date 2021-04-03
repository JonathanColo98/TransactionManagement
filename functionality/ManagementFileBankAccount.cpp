
#include "ManagementFileBankAccount.h"
#include <iostream>
#include <string>
#include <utility>

ManagementFileBankAccount::ManagementFileBankAccount(BankAccount bankAccount) : bankAccount(std::move(bankAccount)) {}

bool ManagementFileBankAccount::withdraw(const Transaction& transaction) {
    if (bankAccount.getBalance() < transaction.getAmount()) {
        std::cout << "Balance minor of amount";
        return false;
    } else {
        bankAccount.setNewBalance(bankAccount.getBalance() - transaction.getAmount());
        return true;
    }
}

bool ManagementFileBankAccount::deposit(const Transaction& transaction) {
    if(transaction.getAmount() <= 0) {
        return false;
    } else {
        bankAccount.setNewBalance(bankAccount.getBalance() + transaction.getAmount());
        return true;
    }
}

bool ManagementFileBankAccount::writeToFileBankAccount(std::ofstream &fileOutBankAccount) {
    fileOutBankAccount.open("BankAccountOutput.txt", std::ios_base::out | std::ios_base::trunc);

    if(fileOutBankAccount.is_open()) {
        fileOutBankAccount << bankAccount;
        fileOutBankAccount.close();
        return true;
    } else {
        return false;
    }
}

bool ManagementFileBankAccount::readFromFileBankAccount(std::ifstream &fileInBankAccount) {
    fileInBankAccount.open("BankAccountInput.txt", std::ios_base::in);

    if(fileInBankAccount.is_open()) {
        while (fileInBankAccount.good()) {
            fileInBankAccount >> bankAccount;
        }
        fileInBankAccount.close();
        return true;
    } else {
        return false;
    }
}




