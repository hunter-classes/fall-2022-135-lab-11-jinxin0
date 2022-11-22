#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "profile.h"
#include "network.h"

TEST_CASE("Task A")
{
    Profile p("testUser", "testDisplay");
    CHECK(p.getUsername() == "testUser");
    CHECK(p.getFullName() == "testDisplay (@testUser)");
    p.setDisplayName("abc");
    CHECK(p.getFullName() == "abc (@testUser)");
}

TEST_CASE("Task B")
{
    Profile p("testUser", "testDisplay");
    Network n;
    CHECK(n.addUser(p.getUsername(), p.getFullName()) != 0);
    CHECK(n.addUser(p.getUsername(), p.getFullName()) == 0);
    CHECK(n.addUser("mario", "Mario2") != 0);
}
