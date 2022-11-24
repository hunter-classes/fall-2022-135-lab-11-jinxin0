#include <iostream>

#include "profile.h"
#include "network.h"
    
#define PRINTLN(x) std::cout << x << '\n';

int main()
{
    Profile p("testUser", "testDisplay");
    PRINTLN(p.getUsername());
    PRINTLN(p.getFullName());
    p.setDisplayName("abc");
    PRINTLN(p.getFullName());

    Network n;
    PRINTLN(std::boolalpha << n.addUser(p.getUsername(), p.getFullName()));
    PRINTLN(std::boolalpha << n.addUser(p.getUsername(), p.getFullName()));

    n.addUser("testUser2", "testDisplay2");
    PRINTLN(std::boolalpha << n.follow(p.getUsername(), "testUser2"));
    n.printDot();
    return 0;
}
