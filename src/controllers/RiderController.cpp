#include <fstream>
#include <iostream>
#include <string>

#include "../classes/Rider.h"
#include "../classes/User.h"
#include "../utils/generateUserOptions.h"
#include "authController.h"

void riderController(Rider* rider) {
    std::cout << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "Rider's Menu" << std::endl;
    std::cout << "--------------------" << std::endl << std::endl;

    std::cout << "Current Balance: AUD " << rider->getCurrentBalance()
              << std::endl
              << std::endl;

    std::cout << "1. Book Ride" << std::endl;
    std::cout << "2. Top Up" << std::endl;
    std::cout << "3. View Ride History" << std::endl;
    std::cout << "4. Change Password" << std::endl << std::endl;

    int riderDecision = generateUserOptions(4);

    switch (riderDecision) {
        case 1:
            rider->bookRide();
            break;
        case 2:
            rider->topUp();
            break;
        case 3:
            std::cout << "View Ride History" << std::endl;
            break;
    }

    riderController(rider);
}