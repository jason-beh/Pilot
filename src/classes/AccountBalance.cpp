#include "AccountBalance.h"

#include <iostream>
#include <string>

using namespace std;

AccountBalance::AccountBalance() {}

bool AccountBalance::pay(int amount) {
    std::cout << "AUD" << amount << " will be deducted from your balance."
              << std::endl;

    return true;
}

AccountBalance::~AccountBalance() {}