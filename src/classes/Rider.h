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

    bool topUp();

    ~Rider();

private:
    static int globalRiderId;

    int riderId;

    int currentBalance;

    void setCurrentBalance(int amount);

    // vector<Ride*> rideHistory

    
    // Ride* bookRide(string destination, string origin, Driver* driver)
};

#endif