#include "AuthController.h"
#include "../classes/User.h"
#include "../classes/Driver.h"
#include "../classes/Rider.h"
#include "RiderController.h"

#include "../utils/getUserNumberedInput.h"

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
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Welcome to Pilot!" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "To begin using Pilot, are you a driver or rider? (Please select your options based on the number)" << std::endl << std::endl;

    std::cout << "1. Rider" << std::endl;
    std::cout << "2. Driver" << std::endl << std::endl;

    int optionChosen = getUserNumberedInput(2);
    bool isRider = (optionChosen == 1);

    return isRider;
}

bool AuthIsUserWantsToLogin() {

    std::cout << "Would you like to sign up for a new account or login?" << std::endl << std::endl;

    std::cout << "1. Login" << std::endl;
    std::cout << "2. Signup" << std::endl << std::endl;

    int optionChosen = getUserNumberedInput(2);
    bool userWantsToLogin = (optionChosen == 1);

    return userWantsToLogin;
}