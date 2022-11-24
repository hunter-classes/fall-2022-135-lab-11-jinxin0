#include <algorithm>
#include <cctype>
#include <iostream>
#include <iomanip>

#include "network.h"

Network::Network()
    : numUsers(0), profiles{}, following{}
{
}

int Network::findID(std::string usrn)
{
    for (std::size_t i = 0; i < MAX_USERS; i++)
    {
        if (profiles[i].getUsername() == usrn)
            return i;
    }
    return -1;
}

bool Network::addUser(std::string usrn, std::string dspn)
{
    if (usrn.empty() || 
        !std::all_of(usrn.begin(), usrn.end(), [](unsigned char c){return std::isalnum(c);}) ||
        findID(usrn) != -1 ||
        numUsers == MAX_USERS)
        return false;

    profiles[numUsers] = Profile(usrn, dspn);
    ++numUsers;
    return true;
}

bool Network::follow(std::string usrn1, std::string usrn2)
{
    if (usrn1 == usrn2)
        return false;

    int u1 = findID(usrn1);
    int u2 = findID(usrn2);
    if (u1 != -1 && u2 != -1)
    {
        following[u1][u2] = true;
        return true;
    }
    return false;
}

void Network::printDot()
{
    std::cout << "digraph {\n";
    for (std::size_t i = 0; i < numUsers; i++)
    {
        std::cout << "\t" << std::quoted('@' + profiles[i].getUsername()) << '\n';
    }
    std::cout << '\n';
    for (std::size_t i = 0; i < numUsers; i++)
    {
        for (std::size_t j = 0; j < numUsers; j++)
        {
            if (following[i][j])
                std::cout << "\t" << std::quoted('@' + profiles[i].getUsername()) << " -> " << std::quoted(profiles[j].getUsername()) << '\n';
        }
    }
    std::cout << "}\n";
}
