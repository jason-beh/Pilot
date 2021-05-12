#include "Rider.h"
#include "User.h"
#include "Auth.h"
#include "CreditCard.h"
#include "OnlineBanking.h"
#include "Cash.h"

#include <string>
#include <iostream>

#include "../utils/generateUserOptions.h"
#include "../utils/getUserNumberInput.h"
#include "../controllers/RiderController.h"

using namespace std;

int Rider::globalRiderId = 1;

Rider::Rider() {
    riderId = globalRiderId++;

    int currentBalance = 0;
    authDetails = new Auth();
}

void Rider::setCurrentBalance(int amount) {
    currentBalance = amount;
}

int Rider::getCurrentBalance() {
    return currentBalance;
}

bool Rider::topUp() {
    std::cout << "How much would you like to topup?" << std::endl;
    int amount = getUserNumberInput();

    std::cout << "Please select a method for topup" << std::endl << std::endl;

    std::cout << "1. Credit Card" << std::endl;
    std::cout << "2. Online Banking" << std::endl << std::endl;

    int choice = generateUserOptions(2);
    int isTopUpSuccessful = false;

    switch(choice) {
        case 1: {
            CreditCard* creditCardPayment = new CreditCard();
            isTopUpSuccessful = creditCardPayment->pay(amount);
            break;
        }
        case 2: {
            OnlineBanking* onlineBankingPayment = new OnlineBanking();
            isTopUpSuccessful = onlineBankingPayment->pay(amount);
            break;
        }
        default:
            break;
    }

    if(isTopUpSuccessful == true) {
        setCurrentBalance(amount + getCurrentBalance());
    }

    return isTopUpSuccessful;
};

Rider::~Rider() {}