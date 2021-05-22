#include <iostream>
#include <cassert>

#include "../../classes/Driver.h"

int main() {
    Driver* driver = new Driver();

    driver->drive();

    delete driver;
    driver = nullptr;
}