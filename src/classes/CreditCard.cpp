#include "CreditCard.h"

#include <string>
#include <iostream>

using namespace std;

CreditCard::CreditCard() {
}

bool CreditCard::pay(int amount) {
    std::cout << "Used credit card number to pay " << amount << std::endl;

    return true;
}

CreditCard::~CreditCard() {}