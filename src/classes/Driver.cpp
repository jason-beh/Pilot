#include "Driver.h"
#include "Auth.h"

#include <string>

using namespace std;

int Driver::globalDriverId = 1;

Driver::Driver() {

    driverId = globalDriverId++;

    isAvailableToDrive = false;
    currentEarnings = 0;
    isDriving = false;

    authDetails = new Auth();
}

bool Driver::setAvailableToDrive(bool state) {
    return state;
};

int Driver::cashOut(int amount) {
    return 0;
};

Driver::~Driver() {}