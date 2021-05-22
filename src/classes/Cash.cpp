#include "Cash.h"

#include <iostream>
#include <string>

using namespace std;

Cash::Cash() {}

bool Cash::pay(int amount) {
    std::cout << "Awesome! Please make sure to pay AUD" << amount
              << " once you have reached your destination." << std::endl;

    return true;
}

Cash::~Cash() {}