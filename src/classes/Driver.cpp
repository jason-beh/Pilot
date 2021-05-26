#include "Driver.h"

#include <unistd.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../utils/createEntryInDatabase.h"
#include "../utils/generateUserOptions.h"
#include "../utils/getEntryInDatabase.h"
#include "../utils/updateEntryInDatabase.h"
#include "User.h"

// Constructor
Driver::Driver() { 
    bool isAvailableToDrive = false; 
}

/**
 * Set the state of availableToDrive
 * @param bool state (true means availableToDrive, while false means the opposite)
 * @return 
 */
void Driver::setAvailableToDrive(bool state) { 
    isAvailableToDrive = state; 
};

/**
 * Get the state of availableToDrive
 * @param 
 * @return bool state (true means availableToDrive, while false means the opposite)
 */
bool Driver::getAvailableToDrive() { 
    return isAvailableToDrive; 
};

/**
 * Create new wrapper function that wraps setCurrentBalance from User
 * to create abstraction on databaseName
 * @param int amount (Amount of balance)
 * @return
 */
void Driver::setCurrentBalance(int amount) {
    User::setCurrentBalance(amount, "balanceDriver");
}

/**
 * Create new wrapper function that wraps getCurrentBalance from User
 * to create abstraction on databaseName
 * @param 
 * @return int amount (Amount of balance)
 */
int Driver::getCurrentBalance() {
    return User::getCurrentBalance("balanceDriver");
}

/**
 * Enable driver to be able to receive clients to fetch riders
 * @param 
 * @return 
 */
void Driver::drive() {
    std::string username = getUsername();

    // Default state when drier is booked or not booked
    std::string isNotBookedState = username + ",isNotBooked";
    std::string isBookedState = username + ",isBooked";

    // Create entry to indicate that driver is now available
    createEntryInDatabase(isNotBookedState, "availableDrivers");
    setAvailableToDrive(true);

    int secondsWaited = 0;
    bool isBooked = false;

    // Infinite loop as long is driver is avaliable to drive the
    while (getAvailableToDrive() == true) {
        // Break loop if there is no matching with riders in 10 seconds
        if (secondsWaited > 5) {
            std::cout
                << "There's no riders at the moment, please try again later."
                << std::endl;

            // Remove entry from pool of available drivers
            setAvailableToDrive(false);
            updateEntryInDatabase(isNotBookedState, "availableDrivers", "",
                                  true);
            break;
        }

        // Handle appropriate console display based on whether the driver is
        // currently booked or finding riders
        if (isBooked == true) {
            std::cout << "Driving rider to destination..." << std::endl;
        } else {
            std::cout << "Waiting for riders..." << std::endl;
            secondsWaited++;
        }

        // Sleep timeout to not overload program
        sleep(2);

        // Check if driver is currently booked
        bool isCurrentlyBooked =
            getEntryInDatabase(isNotBookedState, "availableDrivers", true)
                .empty();

        // Handle logic based on the current states:
        // 1. Driver is previously free but is now booked
        // 2. Driver is previously booked but is now free
        if (isCurrentlyBooked == true && isBooked == false) {
            std::cout << std::endl << "Rider found!" << std::endl << std::endl;
            isBooked = true;
            secondsWaited = 0;
        } else if (isCurrentlyBooked == false && isBooked == true) {
            // Update driver available state to booked state to prompt if the
            // driver wants to continue driving
            updateEntryInDatabase(isNotBookedState, "availableDrivers",
                                  isBookedState, true);
            setCurrentBalance(getCurrentBalance() + 5);

            std::cout << std::endl
                      << "Ride complete! You have earned AUD 5 from that ride!"
                      << std::endl
                      << std::endl;

            // Prompt if driver wants to continue driving
            std::cout << "Would you like to continue finding for rides?"
                      << std::endl;
            std::cout << "1. Yes" << std::endl;
            std::cout << "2. No" << std::endl;

            int option = generateUserOptions(2);

            if (option == 1) {
                // Set driver to be available again
                updateEntryInDatabase(isBookedState, "availableDrivers",
                                      isNotBookedState, true);
            } else {
                // Remove driver from pool of available drivers
                setAvailableToDrive(false);
                updateEntryInDatabase(isBookedState, "availableDrivers", "",
                                      true);
            }

            isBooked = false;
            secondsWaited = 0;
        }
    }
};

// Destructor
Driver::~Driver() {}
