#include <iostream>
#include <cassert>

#include "../../classes/Ride.h"
#include "../../classes/Rider.h"
#include "../../classes/Cash.h"

/**
 * Test Ride Use Amenities
 * 
 * @param
 * @return
 */
int main() {
    Rider* rider = new Rider();
    PaymentMethod* paymentMethod = new Cash();
    Ride* ride = new Ride(std::time(0), rider, 5, "origin", "destination", paymentMethod);
    ride->useAmenities();

    delete ride;
    ride = nullptr;
    delete rider;
    rider = nullptr;
    delete paymentMethod;
    paymentMethod = nullptr;
}