#include "Driver.h"
#include "User.h"
#include "../utils/createEntryInDatabase.h"
#include "../utils/getEntryInDatabase.h"
#include "../utils/generateUserOptions.h"
#include "../utils/updateEntryInDatabase.h"

#include <string>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <vector>

Driver::Driver() {
    bool isAvailableToDrive = false;
}

void Driver::setAvailableToDrive(bool state){
    isAvailableToDrive = state;
};

bool Driver::getAvailableToDrive(){
    return isAvailableToDrive;
};

void Driver::setCurrentBalance(int amount) {
    User::setCurrentBalance(amount, "balanceDriver");
}

int Driver::getCurrentBalance() {
    return User::getCurrentBalance("balanceDriver");
}

void Driver::drive(){
    std::string username = getUsername();

    std::string isNotBookedState = username + ",isNotBooked";
    std::string isBookedState = username + ",isBooked";

    createEntryInDatabase(isNotBookedState, "availableDrivers");

    int secondsWaited = 0;

    bool isBooked = false;

    setAvailableToDrive(true);

    while(getAvailableToDrive() == true) {
        if(secondsWaited > 5) {
            std::cout << "There's no riders at the moment, please try again later." << std::endl;
            setAvailableToDrive(false);
            break;
        }

        if(isBooked == true) {
            std::cout << "Driving rider to destination..." << std::endl;
        } else {
            std::cout << "Waiting for riders..." << std::endl;
            secondsWaited++;
        }

        sleep(2);

        bool isCurrentlyBooked = getEntryInDatabase(isNotBookedState, "availableDrivers", true).empty();

        // 1. Driver is previously free but is now booked
        // 2. Driver is previously booked but is now free
        if(isCurrentlyBooked == true && isBooked == false) {
            std::cout << std::endl << "Rider found!" << std::endl << std::endl;
            isBooked = true;
            secondsWaited = 0;
        } else if(isCurrentlyBooked == false && isBooked == true) {
            updateEntryInDatabase(isNotBookedState, "availableDrivers", isBookedState, true);

            setCurrentBalance(getCurrentBalance() + 5);
            std::cout << std::endl << "Ride complete! You have earned AUD 5 from that ride!" << std::endl << std::endl;

            // prompt user to continue driving or not
            std::cout << "Would you like to continue finding for rides?" << std::endl;
            std::cout << "1. Yes" << std::endl;
            std::cout << "2. No" << std::endl;

            int option = generateUserOptions(2);

            if(option == 1) {
                updateEntryInDatabase(isBookedState, "availableDrivers", isNotBookedState, true);
            } else {
                setAvailableToDrive(false);
                updateEntryInDatabase(isBookedState, "availableDrivers", "", true);
            }

            isBooked = false;
            secondsWaited = 0;
        }

    }
};


Driver::~Driver() {}
