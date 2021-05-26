#include <iostream>
#include <cassert>

#include "../../classes/LuxuryRide.h"
#include "../../classes/Rider.h"
#include "../../classes/Cash.h"

/**
 * Test LuxuryRideUseAmenities
 * 
 * @param
 * @return
 */
int main() {
    Rider* rider = new Rider();
    PaymentMethod* paymentMethod = new Cash();
    LuxuryRide* ride = new LuxuryRide(std::time(0), rider, 5, "origin", "destination", paymentMethod);

    ride->useAmenities();

    // Free heap memory
    delete ride;
    ride = nullptr;
    delete rider;
    rider = nullptr;
    delete paymentMethod;
    paymentMethod = nullptr;
}