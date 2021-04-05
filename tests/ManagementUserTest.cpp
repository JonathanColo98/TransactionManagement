
#include <gtest/gtest.h>
#include "../functionality/ManagementFileUser.h"

TEST(ManagementUserTest, WriteToFileCorrectly) {
    User userObjectTest("Nome Utente", "nome.utente@email.it", "3645645665");
    std::ofstream fileOutUserTest;
    ManagementFileUser managementUserTest(userObjectTest);
    ASSERT_TRUE(managementUserTest.writeToFileUser(fileOutUserTest));
}

TEST(ManagementUserTest, ReadToFileCorrectly) {
    User userObjectTest("Nome Utente", "nome.utente@email.it", "3645645665");
    std::ifstream fileInUserTest;
    std::ofstream fileOutUserTest;
    ManagementFileUser managementUserTest(userObjectTest);

    fileOutUserTest.open("user.txt", std::ios_base::out | std::ios_base::trunc);

    if(fileOutUserTest.is_open()) {
        fileOutUserTest << userObjectTest;
        fileOutUserTest.close();
    }

    ASSERT_TRUE(managementUserTest.readFromFileUser(fileInUserTest));
}
