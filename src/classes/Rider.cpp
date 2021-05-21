#include "Rider.h"
#include "User.h"
#include "CreditCard.h"
#include "OnlineBanking.h"
#include "Cash.h"
#include "Ride.h"
#include "LuxuryRide.h"
#include "AccountBalance.h"

#include <string>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <fstream>

#include "../utils/generateUserOptions.h"
#include "../utils/getUserNumberInput.h"
#include "../utils/getEntryInDatabase.h"
#include "../utils/createEntryInDatabase.h"
#include "../utils/updateEntryInDatabase.h"
#include "../utils/getUserStringInput.h"
#include "../utils/splitString.h"
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
    std::cout << "How much would you like to topup?" << std::endl;
    int amount = getUserNumberInput("Topup amount: ");

    std::cout << "Please select a method for topup." << std::endl << std::endl;

    std::cout << "1. Credit Card" << std::endl;
    std::cout << "2. Online Banking" << std::endl;

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
    Ride* rideTypeChosen;

    std::string origin = getUserStringInput("Current Location: ", true);
    std::string destination = getUserStringInput("Destination: ", false);

    std::cout << std::endl << "Please select the type of ride: " << std::endl;
    std::cout << "1. Standard" << std::endl;
    std::cout << "2. Comfort" << std::endl;
    std::cout << "3. Luxury" << std::endl;

    int userRideOption = generateUserOptions(3);

    std::cout << "The price will be a flat rate of AUD 5, as Pilot has just launched! Would you like to proceed?" << std::endl;
    std::cout << "1. Yes" << std::endl;
    std::cout << "2. No" << std::endl;

    int option = generateUserOptions(2);

    if(option == 1) {
        std::cout << "Please select your preferred payment method: " << std::endl;
        std::cout << "1. Credit Card" << std::endl;
        std::cout << "2. Online Banking" << std::endl;
        std::cout << "3. Cash" << std::endl;
        std::cout << "4. Account Balance" << std::endl;

        int choice = generateUserOptions(4);

        PaymentMethod* paymentMethod;

        switch(choice) {
            case 1: {
                paymentMethod = new CreditCard();
                break;
            }
            case 2: {
                paymentMethod = new OnlineBanking();
                break;
            }
            case 3: {
                paymentMethod = new Cash();
            }
            case 4: {
                if(getCurrentBalance() < 5) {
                    std::cout << "You don't have not enough balance in your account. Please top up before booking a ride." << std::endl;
                    return;
                }
                paymentMethod = new AccountBalance();
            }
            default:
                break;
        }

        paymentMethod->pay(5);

        switch(userRideOption) {
            case 1:
                rideTypeChosen = new Ride(std::time(0), this, 5, origin, destination, paymentMethod);
                break;
            case 3:
                rideTypeChosen = new LuxuryRide(std::time(0), this, 5, origin, destination, paymentMethod);
                break;
            default:
                break;
        }

        bool isRideConfirmed = false;
        int secondsWaited = 0;
        std::vector<std::string> confirmedDriver;

        std::cout << std::endl;

        while(isRideConfirmed == false) {
            if(secondsWaited > 10) {
                std::cout << std::endl << "Unfortunately, there is no driver at the moment. Please try booking again later." << std::endl;
                break;
            }

            secondsWaited++;
            std::cout << "Finding drivers..." << std::endl; 
            sleep(2);

            std::string currentLine;
            std::string databasePath = "src/database/availableDrivers.txt";
            std::ifstream fileStream(databasePath);

            // Read the entire file line by line
            while (getline(fileStream, currentLine)) {
                if(currentLine.length() > 0) {
                    std::vector<std::string> currentDriver = splitString(currentLine, ",");
                    if(currentDriver[1] == "isNotBooked") {
                        isRideConfirmed = true;
                        confirmedDriver = currentDriver;
                        break;
                    }
                    
                }
            }

            fileStream.close();

            if(isRideConfirmed == true) {
                break;
            }
        }

        if(isRideConfirmed == true) {
            std::cout << std::endl << "Found driver!" << std::endl;

            // std::vector<std::string> prevDriverEntry = confirmedDriver;
            // confirmedDriver[1] = "isBooked";

            std::string prevDriverEntry = confirmedDriver[0] + ",isNotBooked";
            std::string newDriverEntry = confirmedDriver[0] + ",isBooked";

            updateEntryInDatabase(prevDriverEntry, "availableDrivers", newDriverEntry, true);

            rideTypeChosen->useAmenities();
            setCurrentBalance(getCurrentBalance() - 5);

            updateEntryInDatabase(newDriverEntry, "availableDrivers", prevDriverEntry, true);
        }

    }
}

Rider::~Rider() {}