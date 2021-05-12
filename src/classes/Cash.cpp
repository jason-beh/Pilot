#include "Cash.h"

#include <string>
#include <iostream>

using namespace std;

Cash::Cash() {
}

bool Cash::pay(int amount) {
    std::cout << "Please make sure to pay AUD" << amount << " once you have reached your destination" << std::endl;

    return true;
}

Cash::~Cash() {}