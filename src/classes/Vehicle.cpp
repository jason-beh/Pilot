#include "Vehicle.h"
#include <string>

using namespace std;

int Vehicle::globalVehicleId = 1;

Vehicle::Vehicle() {
    vehicleId = globalVehicleId++;
}

void Vehicle::listenToRadio() {

};

void Vehicle::setRadio(bool mode) {

};

Vehicle::~Vehicle() {}