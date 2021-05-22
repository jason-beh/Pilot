#include <fstream>
#include <iostream>
#include <string>

#include "../classes/Rider.h"
#include "../classes/User.h"
#include "../utils/generateUserOptions.h"
#include "driverController.h"

void riderController(Rider* rider) {
    bool quitApp = false;

    std::cout << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "Rider's Menu" << std::endl;
    std::cout << "--------------------" << std::endl << std::endl;

    std::cout << "Current Balance: AUD " << rider->getCurrentBalance()
              << std::endl
              << std::endl;

    std::cout << "1. Book Ride" << std::endl;
    std::cout << "2. Top Up" << std::endl;
    std::cout << "3. Exit App" << std::endl;

    int riderDecision = generateUserOptions(3);

    switch (riderDecision) {
        case 1:
            rider->bookRide();
            break;
        case 2:
            rider->topUp();
            break;
        case 3:
            quitApp = true;
            break;
    }

    if(quitApp == false) {
        riderController(rider);
    } 
}