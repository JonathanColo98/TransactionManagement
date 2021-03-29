
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../entities/User.h"

TEST(UserTest, EntityCorrectCreation) {
    User userObjectTest("Nome Utente", "nome.utente@email.it", "3645645665");
    ASSERT_THAT("Nome Utente", userObjectTest.getNominative());
    ASSERT_THAT("nome.utente@email.it", userObjectTest.getEmail());
    ASSERT_THAT("3645645665", userObjectTest.getTelephoneNumber());
}

TEST(UserTest, TestToString) {
    User userObjectTest("Nome Utente", "name.user@email.it", "3645645665");
    ASSERT_THAT("[Nominativo: Nome Utente E-mail: nome.utente@email.it Numero di telefono: 3645645665]", userObjectTest.toString());
}