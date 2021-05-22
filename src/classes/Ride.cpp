#include "Ride.h"

#include <iostream>
#include <string>

#include "../utils/generateUserOptions.h"

using namespace std;

Ride::Ride(time_t createdAt, Rider *rider, int price, std::string origin,
           std::string destination, PaymentMethod *paymentMethod) {
    this->createdAt = createdAt;
    this->rider = rider;
    this->price = price;
    this->origin = origin;
    this->destination = destination;
    this->paymentMethod = paymentMethod;
}

void Ride::useAmenities() {
    // Display amenities choices
    std::cout << std::endl
              << "Welcome to your ride! You can now do the following: "
              << std::endl;

    if (isRadioOn == false) {
        std::cout << "1. Turn on radio" << std::endl;
    } else {
        std::cout << "1. Turn off radio" << std::endl;
    }
    std::cout << "2. Complete Ride" << std::endl;

    // Get user option
    int option = generateUserOptions(2);

    if (option == 1) {
        if (isRadioOn == false) {
            isRadioOn = true;
            std::cout << "Radio is now turned on!" << std::endl;
        } else {
            isRadioOn = false;
            std::cout << "Radio is now turned off!" << std::endl;
        }

        useAmenities();
    }
};

Ride::~Ride() {}