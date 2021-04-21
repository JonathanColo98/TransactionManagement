
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../entities/User.h"

TEST(UserTest, EntityCorrectCreation) {
    User userObjectTest("Nome Utente", "nome.utente@email.it", "3645645665");
    ASSERT_THAT("Nome Utente", userObjectTest.getNominative());
    ASSERT_THAT("nome.utente@email.it", userObjectTest.getEmail());
    ASSERT_THAT("3645645665", userObjectTest.getTelephoneNumber());
}

TEST(UserTest, UserTestComparator) {
    User userObjectTest("Nome Utente", "nome.utente@email.it", "3645645665");
    User userObjectTest2("Nome Utente", "nome.utente@email.it", "3645645665");
    User userObjectEmpty("","","");
    ASSERT_TRUE(userObjectTest == userObjectTest2);
    ASSERT_FALSE(userObjectTest == userObjectEmpty);
}

TEST(UserTest, ToStringTest) {
    User userObjectTest("Nome Utente", "nome.utente@email.it", "3645645665");
    ASSERT_THAT("[Nominativo: Nome Utente E-mail: nome.utente@email.it Numero di telefono: 3645645665]", userObjectTest.toString());
}


TEST(UserTest, WriteToFileCorrectly) {
    User userObjectTest("Nome Utente", "nome.utente@email.it", "3645645665");
    std::ofstream fileOutUserTest;
    ASSERT_TRUE(userObjectTest.writeToFileUser(fileOutUserTest,userObjectTest));
}

TEST(UserTest, ReadToFileCorrectly) {
    User userObjectTest("Nome Utente", "nome.utente@email.it", "3645645665");
    std::ifstream fileInUserTest;
    std::ofstream fileOutUserTest;

    fileOutUserTest.open("user.txt", std::ios_base::out | std::ios_base::trunc);

    if(fileOutUserTest.is_open()) {
        fileOutUserTest << userObjectTest;
        fileOutUserTest.close();
    }

    ASSERT_EQ(userObjectTest, userObjectTest.readFromFileUser(fileInUserTest));
}

