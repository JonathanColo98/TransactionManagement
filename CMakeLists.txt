cmake_minimum_required(VERSION 3.17)
project(TransactionManagement)

set(CMAKE_CXX_STANDARD 11)

add_executable(TransactionManagement main.cpp entities/BankAccount.cpp entities/BankAccount.h entities/Transaction.cpp entities/Transaction.h entities/Bank.cpp entities/Bank.h entities/User.cpp entities/User.h)