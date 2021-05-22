#include "LuxuryRide.h"

#include <iostream>
#include <string>

#include "../utils/generateUserOptions.h"
#include "../utils/getUserStringInput.h"
#include "Ride.h"

LuxuryRide::LuxuryRide(time_t createdAt, Rider *rider, int price,
                       std::string origin, std::string destination,
                       PaymentMethod *paymentMethod)
    : Ride(createdAt, rider, price, origin, destination, paymentMethod) {
    isWineServed = false;
    isMassageChairOn = false;
    currentSong = "";
    currentMovie = "";
}

void LuxuryRide::useAmenities() {

    // Display amenities choices
    std::cout << "Welcome to your ride! You can now do the following: "
              << std::endl;

    std::cout << "1. Drink wine" << std::endl;
    if (isMassageChairOn == true) {
        std::cout << "2. Turn off massage chair" << std::endl;
    } else {
        std::cout << "2. Turn on massage chair" << std::endl;
    }
    std::cout << "3. Choose song" << std::endl;
    std::cout << "4. Choose movie" << std::endl;
    std::cout << "5. Complete ride" << std::endl;

    // Get user option
    int option = generateUserOptions(5);
    switch (option) {
        case 1: {
            if (isWineServed == false) {
                std::cout << "Served wine!" << std::endl << std::endl;
                isWineServed = true;
            } else {
                std::cout << "Wine has run out" << std::endl << std::endl;
            }
            break;
        }
        case 2: {
            if (isMassageChairOn == true) {
                std::cout << "Massage chair is now turned off" << std::endl
                          << std::endl;
                isMassageChairOn = false;
            } else {
                std::cout << "Massage chair is now turned on" << std::endl
                          << std::endl;
                isMassageChairOn = true;
            }
            break;
        }
        case 3: {
            currentSong = getUserStringInput(
                "Please enter a movie you would like to watch: ", true);
            std::cout << std::endl
                      << "Playing chosen song now" << std::endl
                      << std::endl;
            break;
        }
        case 4: {
            currentMovie = getUserStringInput(
                "Please enter a movie you would like to watch: ", true);
            std::cout << std::endl
                      << "Playing chosen movie now" << std::endl
                      << std::endl;
            break;
        }
    }

    // Restart the amenities menu if the user doesn't complete ride
    if (option != 5) {
        useAmenities();
    }
};

LuxuryRide::~LuxuryRide() {}