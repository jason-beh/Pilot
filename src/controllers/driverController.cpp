#include <fstream>
#include <iostream>
#include <string>

#include "../classes/Driver.h"
#include "../classes/User.h"
#include "../utils/generateUserOptions.h"
#include "driverController.h"

void driverController(Driver* driver) {
    std::cout << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "Driver's Menu" << std::endl;
    std::cout << "--------------------" << std::endl << std::endl;

    std::cout << "Current Balance: AUD " << driver->getCurrentBalance()
              << std::endl
              << std::endl;

    std::cout << "1. Drive" << std::endl;
    std::cout << "2. Exit" << std::endl;

    int driverDecision = generateUserOptions(2);

    switch (driverDecision) {
        case 1:
            driver->drive();
            break;
        case 2:
            std::cout << "Quit app!" << std::endl;
            break;
    }

    driverController(driver);
}