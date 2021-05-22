#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

// #include "Ride.h"

class User {
    private:
        std::string username;
        std::string password;
        bool isLoggedIn;
        int currentBalance;

    public:
        User();
        ~User();

        void setUsername(std::string newUsername);
        void setPassword(std::string newPassword);
        void setIsLoggedIn(bool isLoggedInStatus);

        bool getIsLoggedIn();
        bool signUp(std::string userType);
        bool login(std::string userType);
        std::string getUsername();

    protected:
        void setCurrentBalance(int amount, std::string databaseName);
        int getCurrentBalance(std::string databaseName);
};

#endif