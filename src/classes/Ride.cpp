#include "Ride.h"

#include <string>

using namespace std;

int Ride::globalRideId = 1;

Ride::Ride() {
    rideId = globalRideId++;
}

Ride::~Ride() {}