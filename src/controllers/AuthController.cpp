#include "authController.h"
#include "../classes/User.h"
#include "../classes/Driver.h"
#include "../classes/Rider.h"
#include "riderController.h"
#include "driverController.h"

#include "../utils/generateUserOptions.h"

#include <fstream>
#include <iostream>
#include <string>

void authController()
{
    bool isRider = isRiderOrDriver();
    bool isUserLogin = isUserWantsToLogin();

    if(isRider == true) {
        
        Rider* rider = new Rider();

        if(isUserLogin == true) 
            rider->login("Rider");
        else 
            rider->signUp("Rider");

        riderController(rider);

    } else {
        Driver* driver = new Driver();

        if(isUserLogin == true) 
            driver->login("Driver");
        else 
            driver->signUp("Driver");

        driverController(driver);
    }
    
}

bool isRiderOrDriver() {
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Welcome to Pilot!" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "To begin using Pilot, are you a driver or rider? (Please select your options based on the number)" << std::endl << std::endl;

    std::cout << "1. Rider" << std::endl;
    std::cout << "2. Driver" << std::endl;

    int optionChosen = generateUserOptions(2);
    bool isRider = (optionChosen == 1);

    return isRider;
}

bool isUserWantsToLogin() {
    std::cout << "Would you like to sign up for a new account or login?" << std::endl << std::endl;

    std::cout << "1. Login" << std::endl;
    std::cout << "2. Signup" << std::endl;

    int optionChosen = generateUserOptions(2);
    bool userWantsToLogin = (optionChosen == 1);

    return userWantsToLogin;
}