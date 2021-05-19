#include "Rider.h"
#include "User.h"
#include "CreditCard.h"
#include "OnlineBanking.h"
#include "Cash.h"

#include <string>
#include <iostream>

#include "../utils/generateUserOptions.h"
#include "../utils/getUserNumberInput.h"
#include "../utils/getEntryInDatabase.h"
#include "../utils/createEntryInDatabase.h"
#include "../controllers/riderController.h"

using namespace std;

int Rider::globalRiderId = 1;

Rider::Rider() {
    riderId = globalRiderId++;

    int currentBalance = 0;
}

void Rider::setCurrentBalance(int amount) {
    currentBalance = amount;
}

int Rider::getCurrentBalance() {
    getBalanceFromDB();

    return currentBalance;
}

void Rider::getBalanceFromDB() {
    std::string username  = getUsername();

    vector<std::string> databaseResults = getEntryInDatabase(username, "balanceRider", false);

    if(databaseResults.size() != 0) {
        std::string balance = databaseResults[1];
        setCurrentBalance(stoi(balance));
    } else {
        std::string newDatabaseEntry = username + ",0";
        createEntryInDatabase(newDatabaseEntry, "balanceRider");
        setCurrentBalance(0);
    }
}

bool Rider::topUp() {
    std::cout << "How much would you like to topup?" << std::endl;
    int amount = getUserNumberInput("Topup amount: ");

    std::cout << "Please select a method for topup." << std::endl << std::endl;

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