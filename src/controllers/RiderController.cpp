#include "AuthController.h"
#include "../classes/User.h"
#include "../classes/Rider.h"

#include <fstream>
#include <iostream>
#include <string>

void RiderController(Rider* rider) {   
    std::cout << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "Driver's Menu" << std::endl;
    std::cout << "--------------------" << std::endl << std::endl;

    std::cout << "Current Balance: AUD " << rider->getCurrentBalance() << std::endl << std::endl;

    std::cout << "1. Book Ride" << std::endl;
    std::cout << "2. Top Up" << std::endl;
    std::cout << "3. View Ride History" << std::endl;
    std::cout << "4. Change Password" << std::endl;

    int optionChosen = 0;

    while(true) {
        std::cout << "Enter decision: ";
        std::cin >> optionChosen;

        switch(optionChosen) {
            case 1: 
                std::cout << "Book Ride" << std::endl;
                break;
            case 2: 
                std::cout << "Top Up" << std::endl;
                break;
            case 3: 
                std::cout << "View Ride History" << std::endl;
                break;
            case 4:
                std::cout << "Change Password" << std::endl;
                break;
            default:
                std::cout << "Please enter 1, 2, 3, or 4 only" << std::endl;
        }

        
    }


}