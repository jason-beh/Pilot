#include "CreditCard.h"

#include <ctime>
#include <iostream>
#include <string>
#include <vector>

#include "../libs/creditCardValidator.h"
#include "../utils/getUserNumberInput.h"
#include "../utils/getUserLongNumberInput.h"

using namespace std;

CreditCard::CreditCard() {}

bool CreditCard::pay(int amount) {
    long int creditCardNumber = getUserLongNumberInput("Credit Card Number: ");
    int expiryDateYear = getUserNumberInput("Expiry Date Year (e.g. 2001): ");
    int expiryDateMonth = getUserNumberInput("Expiry Date Month (e.g. 12): ");
    getUserNumberInput("CVC: ");

    const int sizeLimit = 10;
    char formattedTime[sizeLimit];
    time_t currentTime = time(0);
    strftime(formattedTime, sizeLimit, "%m/%d/%Y", localtime(&currentTime));

    vector<std::string> dateBreakdown;
    std::string tempString = "";
    for (int i = 0; i < sizeLimit; i++) {
        if (formattedTime[i] == '/') {
            dateBreakdown.push_back(tempString);
            tempString = "";
        } else {
            tempString += formattedTime[i];
        }
    }
    dateBreakdown.push_back(tempString);

    int currentMonth = stoi(dateBreakdown[0]);
    int currentYear = stoi(dateBreakdown[2]);

    if ((currentYear > expiryDateYear) ||
        (currentYear == expiryDateYear && currentMonth > expiryDateMonth) ||
        (isValid(creditCardNumber) == false)) {
        std::cout << "Invalid Credit Card!" << std::endl;
        return false;
    }

    return true;
}

CreditCard::~CreditCard() {}