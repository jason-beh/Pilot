#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <vector>

#include "Auth.h"
#include "User.h"

class Driver: public User
{
public:
    Driver();


    bool setAvailableToDrive(bool state);
    int cashOut(int amount);

    ~Driver();

private:
    static int globalDriverId;

    int driver_id;

    bool isAvailableToDrive;
    int currentEarnings;
    bool isDriving;
    // Vehicle* driverVehicle;
    // vector<Bookings*> bookingHistory

};

#endif