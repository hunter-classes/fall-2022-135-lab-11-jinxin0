#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"

TEST_CASE("Task A")
{
    Profile p("testUser", "testDisplay");
    CHECK(p.getUsername() == "testUser");
    CHECK(p.getFullName() == "testDisplay (@testUser)");
    p.setDisplayName("abc");
    CHECK(p.getFullName() == "abc (@testUser)");
}
