#include "Cash.h"

#include <iostream>
#include <string>

// Constructor
Cash::Cash() {}

/**
 * Pay using Cash
 * @param int amount (Amount of money that the user will pay)
 * @return bool (true if the payment is successful)
 */
bool Cash::pay(int amount) {
    std::cout << "Awesome! Please make sure to pay AUD" << amount
              << " once you have reached your destination." << std::endl;

    return true;
}

// Destructor
Cash::~Cash() {}