#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <vector>

#include "User.h"

class Driver: public User
{
public:
    Driver();

    void drive();
    int getCurrentEarnings();

    ~Driver();

private:
    bool isAvailableToDrive;
    int currentEarnings;

    void setAvailableToDrive(bool state);
    bool getAvailableToDrive();
    void setCurrentEarnings(int amount);
};

#endif