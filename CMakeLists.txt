cmake_minimum_required(VERSION 3.17)
project(TransactionManagement)

set(CMAKE_CXX_STANDARD 11)

add_executable(TransactionManagement main.cpp entities/BankAccount.cpp entities/BankAccount.h entities/Transaction.cpp entities/Transaction.h entities/Bank.cpp entities/Bank.h entities/User.cpp entities/User.h tests/UserTest.cpp tests/TransactionTest.cpp tests/BankAccountTest.cpp tests/BankTest.cpp functionality/ManagementUser.cpp functionality/ManagementUser.h functionality/ManagementFileBankAccount.cpp functionality/ManagementFileBankAccount.h tests/ManagementFileBankAccountTest.cpp)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
target_link_libraries(TransactionManagement gtest gtest_main)