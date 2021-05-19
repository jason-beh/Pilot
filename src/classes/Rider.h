#ifndef RIDER_H
#define RIDER_H

#include <string>
#include <vector>

#include "User.h"

class Rider: public User
{
    public:
        Rider();

        int getCurrentBalance();
        void setCurrentBalance(int amount);
        void getBalanceFromDB();
        bool topUp();
        void bookRide();

        ~Rider();

    private:
        int currentBalance;
};

#endif