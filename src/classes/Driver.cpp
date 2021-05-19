#include "Driver.h"
#include "User.h"

#include <string>

using namespace std;

int Driver::globalDriverId = 1;

Driver::Driver() {

    driverId = globalDriverId++;

    isAvailable = false;
    currentEarnings = 0;
    isDriving = false;
}

void Driver::setIsAvailable() {

};
bool Driver::getIsAvailable() {
    return isAvailable;
};
int Driver::cashOut() {
    return 1;
};


Driver::~Driver() {}