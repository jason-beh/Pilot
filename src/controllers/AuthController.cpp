#include "AuthController.h"
#include "../classes/User.h"
#include "../classes/Driver.h"
#include "../classes/Rider.h"

#include "RiderController.h"

#include <fstream>
#include <iostream>
#include <string>

void AuthController()
{
    bool isRider = AuthIsRiderOrDriver();
    bool isUserWantsToLogin = AuthIsUserWantsToLogin();

    if(isRider == true) {
        
        Rider* rider = new Rider();

        if(isUserWantsToLogin == true) 
            rider->authDetails->login("Rider");
        else 
            rider->authDetails->signUp("Rider");


        RiderController(rider);

    } else {
        Driver* driver = new Driver();

        if(isUserWantsToLogin == true) 
            driver->authDetails->login("Driver");
        else 
            driver->authDetails->signUp("Driver");
    }
    
}

bool AuthIsRiderOrDriver() {
    bool isRider = false;
    int optionChosen = 0;

    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Welcome to Pilot!" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "To begin using Pilot, are you a driver or rider? (Please select your options based on the number)" << std::endl << std::endl;

    std::cout << "1. Rider" << std::endl;
    std::cout << "2. Driver" << std::endl << std::endl;

    while(true) {
        std::cout << "Enter decision: ";
        std::cin >> optionChosen;

        if(optionChosen == 1 || optionChosen == 2) {
            isRider = (optionChosen == 1);
            break;
        }

        std::cout << "Please enter 1 or 2" << std::endl;
    }

    return isRider;
}

bool AuthIsUserWantsToLogin() {
    int optionChosen = 0;
    bool userWantsToLogin = false;

    std::cout << "Would you like to sign up for a new account or login?" << std::endl << std::endl;

    std::cout << "1. Login" << std::endl;
    std::cout << "2. Signup" << std::endl << std::endl;

    while(true) {
        std::cout << "Enter decision: ";
        std::cin >> optionChosen; 

        if(optionChosen == 1 || optionChosen == 2) {
            userWantsToLogin = (optionChosen == 1);
            break;
        }

        std::cout << "Please enter 1 or 2" << std::endl;
    }

    return userWantsToLogin;
}