#include <iostream>
#include <cassert>

#include "../../classes/Ride.h"
#include "../../classes/Rider.h"
#include "../../classes/Cash.h"

int main() {
    Rider* rider = new Rider();

    rider->bookRide();

    delete rider;
    rider = nullptr;
}