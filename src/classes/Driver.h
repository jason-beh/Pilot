#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <vector>

#include "User.h"

class Driver: public User
{
public:
    Driver();

    void setIsAvailable();
    bool getIsAvailable();
    int cashOut();

    ~Driver();

private:
    static int globalDriverId;

    int driverId;

    bool isAvailable;
    int currentEarnings;
    bool isDriving;
};

#endif