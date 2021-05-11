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

    ~Rider();

private:
    static int globalRiderId;

    int rider_id;

    int currentBalance;
    // vector<Bookings*> bookingHistory

    bool topUp(int amount);
    // Booking* bookRide(string destination, string origin, Driver* driver)
};

#endif