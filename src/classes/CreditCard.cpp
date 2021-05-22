#include "CreditCard.h"

#include <ctime>
#include <iostream>
#include <string>
#include <vector>

#include "../libs/creditCardValidator.h"
#include "../utils/getUserLongNumberInput.h"
#include "../utils/getUserNumberInput.h"

using namespace std;

CreditCard::CreditCard() {}

bool CreditCard::pay(int amount) {
    // Obtain user input
    long int creditCardNumber = getUserLongNumberInput("Credit Card Number: ");
    int expiryDateYear = getUserNumberInput("Expiry Date Year (e.g. 2001): ");
    int expiryDateMonth = getUserNumberInput("Expiry Date Month (e.g. 12): ");
    int cvc = getUserNumberInput("CVC: ");

    // Default values to compare against (will be implementing currentDate in
    // the future)
    int currentMonth = 5;
    int currentYear = 2021;
    std::string lengthCVC = std::to_string(cvc);

    // Reject the credit card details and restart the credit card process again
    // if one of the following:
    // 1. Credit card expiry month is due
    // 2. Credit card expiry year is due
    // 3. Credit card validator check fail
    // 4. Input month is more than 12 or less than 1
    // 5. CVC length is more than 3 or none
    if ((currentYear > expiryDateYear) ||
        (currentYear == expiryDateYear && currentMonth >= expiryDateMonth) ||
        (isValid(creditCardNumber) == false) || lengthCVC.length() == 0 ||
        lengthCVC.length() > 3 || expiryDateMonth > 12 || expiryDateMonth < 1) {
        std::cout << "Invalid Credit Card!" << std::endl;
        return pay(amount);
    }

    return true;
}

CreditCard::~CreditCard() {}