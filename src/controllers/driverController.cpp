#include <fstream>
#include <iostream>
#include <string>

#include "../classes/Driver.h"
#include "../classes/User.h"
#include "../utils/generateUserOptions.h"
#include "driverController.h"

/**
 * Driver controller to determine user's action at the menu
 * @param
 * @return
 */
void driverController(Driver* driver) {
    bool quitApp = false;

    std::cout << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "Driver's Menu" << std::endl;
    std::cout << "--------------------" << std::endl << std::endl;

    std::cout << "Current Balance: AUD " << driver->getCurrentBalance()
              << std::endl
              << std::endl;

    std::cout << "1. Drive" << std::endl;
    std::cout << "2. Exit" << std::endl;

    // Get driver's current decision
    int driverDecision = generateUserOptions(2);
    switch (driverDecision) {
        case 1:
            driver->drive();
            break;
        case 2:
            quitApp = true;
            break;
    }

    // Recursively call the function if the driver does not want to quit
    if(quitApp == false) {
        driverController(driver);
    } 
}