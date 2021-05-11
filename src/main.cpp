#include <iostream>

#include "controllers/AuthController.h"
#include "utils/createEntryInDatabase.h"
#include "utils/searchEntryInDatabase.h"

#include "classes/Auth.h"
#include "classes/User.h"
#include "classes/Driver.h"
#include "classes/Rider.h"

int main()
{  
    bool isRider = false;

    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Welcome to Pilot!" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "To begin using Pilot, are you a driver or rider? (Please select your options based on the number)" << std::endl << std::endl;

    std::cout << "1. Rider" << std::endl;
    std::cout << "2. Driver" << std::endl << std::endl;

    int optionChosen = 0;

    while(true) {
        std::cout << "Enter decision: ";
        std::cin >> optionChosen;

        if(optionChosen == 1 || optionChosen == 2) {
            isRider = (optionChosen == 1);
            break;
        }

        std::cout << "Please enter 1 or 2" << std::endl;
    }

    std::cout << "Would you like to sign up for a new account or login?" << std::endl << std::endl;

    std::cout << "1. Login" << std::endl;
    std::cout << "2. Signup" << std::endl << std::endl;

    bool userWantsToLogin = false;
    
    while(true) {
        std::cout << "Enter decision: ";
        std::cin >> optionChosen; 

        if(optionChosen == 1 || optionChosen == 2) {
            userWantsToLogin = (optionChosen == 1);
            break;
        }

        std::cout << "Please enter 1 or 2" << std::endl;
    }

    if(isRider == true) {
        
        Rider* rider = new Rider();

        if(userWantsToLogin == true) 
            rider->authDetails->login("Rider");
        else 
            rider->authDetails->signUp("Rider");
    } else {
        Driver* driver = new Driver();

        if(userWantsToLogin == true) 
            driver->authDetails->login("Driver");
        else 
            driver->authDetails->signUp("Driver");
    }


    // std::string username;

    // while(true) {
    //     std::cout << "Username: ";
    //     std::cin >> username;

    //     if(optionChosen == 1 || optionChosen == 2) {
    //         break;
    //     }

    //     std::cout << "Please enter 1 or 2" << std::endl;
    // }

    // std::string password;



    // std::cout << "Password: ";
    // std::cin >> password;

    // std::string searchQuery = username + "," + password;

    // if(optionChosen == 1) {
    //     searchEntryInDatabase(searchQuery, "authRider");
    // } else if(optionChosen == 2) {
    //     searchEntryInDatabase(searchQuery, "authDriver");
    // }

    // createEntryInDatabase("hello", "auth");
    // std::cout << searchEntryInDatabase("hello", "auth");
}

/*
    Login -> 
*/