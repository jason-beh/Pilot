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

/**
 * Authentication controller to distinguish if users:
 * 1. Wants to login or signup
 * 2. Is a Driver or a Rider
 * @param
 * @return
 */
void authController()
{
    bool isRider = isRiderOrDriver();
    bool isUserLogin = isUserWantsToLogin();

    // Handle multiple scenarios:
    // 1. Rider & Login
    // 2. Rider & SignUp
    // 3. Driver & Login
    // 4. Driver & SignUp
    if(isRider == true) {
        
        Rider* rider = new Rider();

        if(isUserLogin == true) 
            rider->login("Rider");
        else 
            rider->signUp("Rider");

        riderController(rider);

        std::cout << "We hope to see you again, " << rider->getUsername() << "!" << std::endl;

        // Free memory of rider
        delete rider;
        rider = nullptr;

    } else {
        Driver* driver = new Driver();

        if(isUserLogin == true) 
            driver->login("Driver");
        else 
            driver->signUp("Driver");

        driverController(driver);

        std::cout << "We hope to see you again, " << driver->getUsername() << "!" << std::endl;

        // Free memory of driver
        delete driver;
        driver = nullptr;
    }
    
}

/**
 * Check if User is a Rider or a Driver
 * @param
 * @return bool state (true means the User is a Rider, false means the User is a Driver)
 */
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

/**
 * Check if User wants to login or signup
 * @param
 * @return bool state (true means the User wants to login, false means the User wants to signup)
 */
bool isUserWantsToLogin() {
    std::cout << "Would you like to sign up for a new account or login?" << std::endl << std::endl;

    std::cout << "1. Login" << std::endl;
    std::cout << "2. Signup" << std::endl;

    int optionChosen = generateUserOptions(2);
    bool userWantsToLogin = (optionChosen == 1);

    return userWantsToLogin;
}