#include "AccountBalance.h"

#include <iostream>
#include <string>

// Constructor
AccountBalance::AccountBalance() {}

/**
 * Pay using AccountBalance
 * @param int amount (Amount of money that the user will pay)
 * @return bool (true if the payment is successful)
 */
bool AccountBalance::pay(int amount) {
    std::cout << "AUD" << amount << " will be deducted from your balance."
              << std::endl;

    return true;
}

// Destructor
AccountBalance::~AccountBalance() {}