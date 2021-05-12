#include <fstream>
#include <iostream>
#include <string>

#include "../classes/Rider.h"
#include "../classes/User.h"
#include "../utils/getUserNumberedInput.h"
#include "AuthController.h"

void RiderController(Rider* rider) {
    std::cout << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "Driver's Menu" << std::endl;
    std::cout << "--------------------" << std::endl << std::endl;

    std::cout << "Current Balance: AUD " << rider->getCurrentBalance()
              << std::endl
              << std::endl;

    std::cout << "1. Book Ride" << std::endl;
    std::cout << "2. Top Up" << std::endl;
    std::cout << "3. View Ride History" << std::endl;
    std::cout << "4. Change Password" << std::endl << std::endl;

    int riderDecision = getUserNumberedInput(4);

    switch (riderDecision) {
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
    }
}