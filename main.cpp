#include <iostream>

#include "profile.h"
    
template<typename T>
void PRINTLN(T x)
{
    std::cout << x << '\n';
}
    

int main()
{
    Profile p("testUser", "testDisplay");
    PRINTLN(p.getUsername());
    PRINTLN(p.getFullName());
    p.setDisplayName("abc");
    PRINTLN(p.getFullName());
    return 0;
}
