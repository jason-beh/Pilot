#ifndef RIDER_H
#define RIDER_H

#include <string>
#include <vector>

#include "Auth.h"
#include "User.h"

class Rider: public User
{
public:
    Rider();

    int getCurrentBalance();

    ~Rider();

private:
    static int globalRiderId;

    int riderId;

    int currentBalance;
    // vector<Ride*> rideHistory

    bool topUp(int amount);
    // Ride* bookRide(string destination, string origin, Driver* driver)
};

#endif