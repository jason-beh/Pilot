#include "Rider.h"

#include <unistd.h>

#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

#include "../controllers/riderController.h"
#include "../utils/createEntryInDatabase.h"
#include "../utils/generateUserOptions.h"
#include "../utils/getEntryInDatabase.h"
#include "../utils/getUserNumberInput.h"
#include "../utils/getUserStringInput.h"
#include "../utils/splitString.h"
#include "../utils/updateEntryInDatabase.h"
#include "AccountBalance.h"
#include "Cash.h"
#include "CreditCard.h"
#include "LuxuryRide.h"
#include "OnlineBanking.h"
#include "Ride.h"
#include "User.h"

// Constructor
Rider::Rider() { 
    int currentBalance = 0; 
}

/**
 * Create new wrapper function that wraps setCurrentBalance from User
 * to create abstraction on databaseName
 * @param int amount (Amount of balance)
 * @return
 */
void Rider::setCurrentBalance(int amount) {
    User::setCurrentBalance(amount, "balanceRider");
}

/**
 * Create new wrapper function that wraps getCurrentBalance from User
 * to create abstraction on databaseName
 * @param 
 * @return int amount (Amount of balance)
 */
int Rider::getCurrentBalance() {
    return User::getCurrentBalance("balanceRider");
}

/**
 * Topup money into the Rider's account based on the paymentMethod selected in the prompt
 * @param 
 * @return 
 */
bool Rider::topUp() {
    // Prompt user to provide topup amount
    std::cout << "How much would you like to topup?" << std::endl;
    int amount = getUserNumberInput("Topup amount: ");

    // Prompt user to choose topup method
    std::cout << "Please select a method for topup." << std::endl << std::endl;
    std::cout << "1. Credit Card" << std::endl;
    std::cout << "2. Online Banking" << std::endl;

    int choice = generateUserOptions(2);
    int isTopUpSuccessful = false;

    switch (choice) {
        case 1: {
            CreditCard *creditCardPayment = new CreditCard();
            isTopUpSuccessful = creditCardPayment->pay(amount);
            break;
        }
        case 2: {
            OnlineBanking *onlineBankingPayment = new OnlineBanking();
            isTopUpSuccessful = onlineBankingPayment->pay(amount);
            break;
        }
        default:
            break;
    }

    // Increase user currentBalance based on successful topup amount
    if (isTopUpSuccessful == true) {
        setCurrentBalance(amount + getCurrentBalance());
    }

    return isTopUpSuccessful;
};

/**
 * Allow Rider to book a Ride to go from one place to another
 * @param 
 * @return 
 */
void Rider::bookRide() {
    // Prompt ride origin and destination
    std::string origin = getUserStringInput("Current Location: ", true);
    std::string destination = getUserStringInput("Destination: ", false);

    // Prompt ride type selection
    std::cout << std::endl << "Please select the type of ride: " << std::endl;
    std::cout << "1. Standard" << std::endl;
    std::cout << "2. Luxury" << std::endl;

    int userRideOption = generateUserOptions(2);

    // Prompt to proceed with current promo price of AUD 5
    std::cout << "The price will be a flat rate of AUD 5, as Pilot has just "
                 "launched! Would you like to proceed?"
              << std::endl;
    std::cout << "1. Yes" << std::endl;
    std::cout << "2. No" << std::endl;

    int option = generateUserOptions(2);

    if (option == 1) {
        // Prompt user to choose payment method
        std::cout << "Please select your preferred payment method: "
                  << std::endl;
        std::cout << "1. Credit Card" << std::endl;
        std::cout << "2. Online Banking" << std::endl;
        std::cout << "3. Cash" << std::endl;
        std::cout << "4. Account Balance" << std::endl;

        int choice = generateUserOptions(4);

        PaymentMethod *paymentMethod;
        Ride *rideTypeChosen;
        bool isPayWithAccountBalance = false;

        switch (choice) {
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
                break;
            }
            case 4: {
                // Reject the booking if the user selected account balance, but
                // there is less than AUD 5 in account balance
                if (getCurrentBalance() < 5) {
                    std::cout << "You don't have not enough balance in your "
                                 "account. Please top up before booking a ride."
                              << std::endl;
                    return;
                }
                paymentMethod = new AccountBalance();
                isPayWithAccountBalance = true;
                break;
            }
            default:
                break;
        }

        // Pay using the chosen payment method
        paymentMethod->pay(5);

        // Create ride based on the chosen ride type
        switch (userRideOption) {
            case 1:
                rideTypeChosen = new Ride(std::time(0), this, 5, origin,
                                          destination, paymentMethod);
                break;
            case 2:
                rideTypeChosen = new LuxuryRide(std::time(0), this, 5, origin,
                                                destination, paymentMethod);
                break;
            default:
                break;
        }

        bool isRideConfirmed = false;
        int secondsWaited = 0;
        std::vector<std::string> confirmedDriver;

        std::cout << std::endl;

        // Search for drivers if ride is not confirmed
        while (isRideConfirmed == false) {
            // Reject the booking if there is no drivers after 10 seconds
            if (secondsWaited > 5) {
                std::cout << std::endl
                          << "Unfortunately, there is no driver at the moment. "
                             "Please try booking again later."
                          << std::endl;
                break;
            }

            // Sleep timeout to prevent overloading in the program
            secondsWaited++;
            std::cout << "Finding drivers..." << std::endl;
            sleep(2);

            std::string currentLine;
            std::string databasePath = "src/database/availableDrivers.txt";
            std::ifstream fileStream(databasePath);

            // Read the entire file line by line
            // Confirm ride if the driver is not booked and is available
            while (getline(fileStream, currentLine)) {
                if (currentLine.length() > 0) {
                    std::vector<std::string> currentDriver =
                        splitString(currentLine, ",");
                    if (currentDriver[1] == "isNotBooked") {
                        isRideConfirmed = true;
                        confirmedDriver = currentDriver;
                        break;
                    }
                }
            }

            fileStream.close();

            // Break the finding drivers loop if ride is confirmed
            if (isRideConfirmed == true) {
                break;
            }
        }

        if (isRideConfirmed == true) {
            std::cout << std::endl << "Found driver!" << std::endl;

            // State when driver is booked and not booked
            std::string prevDriverEntry = confirmedDriver[0] + ",isNotBooked";
            std::string newDriverEntry = confirmedDriver[0] + ",isBooked";

            // Update database to reflect that the driver is now booked
            updateEntryInDatabase(prevDriverEntry, "availableDrivers",
                                  newDriverEntry, true);

            // Allow rider to use the amenities of the ride
            rideTypeChosen->useAmenities();

            // Deduct from account balance after ride, if user chose account
            // balance
            if (isPayWithAccountBalance == true) {
                setCurrentBalance(getCurrentBalance() - 5);
            }

            // Update database to reflect that driver is no longer booked
            updateEntryInDatabase(newDriverEntry, "availableDrivers",
                                  prevDriverEntry, true);

            // Delete appropriate objects
            delete rideTypeChosen;
            rideTypeChosen = nullptr;
        }
    }
}

// Destructor
Rider::~Rider() {}