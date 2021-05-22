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
    int getCurrentBalance();
    void setCurrentBalance(int amount);

    ~Driver();

private:
    bool isAvailableToDrive;

    void setAvailableToDrive(bool state);
    bool getAvailableToDrive();
};

#endif