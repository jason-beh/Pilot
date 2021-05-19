#ifndef RIDE_H
#define RIDE_H

#include <string>

#include "Driver.h"
#include "Rider.h"

class Ride
{
private:
    static int globalRideId;
    int rideId;

    Rider* rider;
    Driver* driver;

    int price;
    std::string origin;
    std::string destination;

public:
    Ride();

    ~Ride();

};

#endif