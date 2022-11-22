#include <algorithm>
#include <cctype>

#include "network.h"

Network::Network()
    : numUsers(0), profiles{}
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
