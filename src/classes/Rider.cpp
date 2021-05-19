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
#include "../utils/updateEntryInDatabase.h"
#include "../controllers/riderController.h"

using namespace std;

Rider::Rider() {
    int currentBalance = 0;
}

void Rider::setCurrentBalance(int amount) {
    std::string username  = getUsername();

    std::string newDatabaseEntry = username + "," + std::to_string(amount);

    updateEntryInDatabase(username, "balanceRider", newDatabaseEntry, false);

    currentBalance = amount;
}

int Rider::getCurrentBalance() {
    if(currentBalance == 0) {
        std::string username  = getUsername();

        vector<std::string> databaseResults = getEntryInDatabase(username, "balanceRider", false);

        if(databaseResults.empty() == false && databaseResults[0] == username) {
            std::string balance = databaseResults[1];
            setCurrentBalance(stoi(balance));
            return stoi(balance);
        } else {
            std::string newDatabaseEntry = username + ",0";
            createEntryInDatabase(newDatabaseEntry, "balanceRider");
            return 0;
        }
    }

    return currentBalance;
}

bool Rider::topUp() {
    std::cout << std::endl << "How much would you like to topup?" << std::endl;
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

void Rider::bookRide() {
    std::string origin, destination;

    std::cout << std::endl << "Current Location: ";
    std::cin.ignore();
    std::getline(std::cin, origin);

    std::cout << "Destination: ";
    std::getline(std::cin, destination);

    std::cout << std::endl << "Please select the type of ride: " << std::endl;
    std::cout << "1. Standard" << std::endl;
    std::cout << "2. Comfort" << std::endl;
    std::cout << "3. Luxury" << std::endl << std::endl;

    int rideType = generateUserOptions(3);

    std::cout << std::endl << "The price will be a flat rate of AUD 5, as Pilot has just launched! Would you like to proceed?" << std::endl;
    std::cout << "1. Yes" << std::endl;
    std::cout << "2. No" << std::endl << std::endl;

    int option = generateUserOptions(2);
    switch(option) {
        case 1:
            std::cout << "Add to waitlist" << std::endl;
            break;
        case 2:
            return;
            break;
        default:
            break;
    }
}

Rider::~Rider() {}