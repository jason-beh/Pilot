#include <iostream>
#include <cassert>

#include "../../classes/Driver.h"

/**
 * Test Driver drive method
 * 
 * @param
 * @return
 */
int main() {
    Driver* driver = new Driver();

    driver->drive();

    delete driver;
    driver = nullptr;
}