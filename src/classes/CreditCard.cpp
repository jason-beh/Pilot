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
    long int creditCardNumber = getUserLongNumberInput("Credit Card Number: ");
    int expiryDateYear = getUserNumberInput("Expiry Date Year (e.g. 2001): ");
    int expiryDateMonth = getUserNumberInput("Expiry Date Month (e.g. 12): ");
    int cvc = getUserNumberInput("CVC: ");

    // const int sizeLimit = 10;
    // char formattedTime[sizeLimit];
    // time_t currentTime = time(0);
    // strftime(formattedTime, sizeLimit, "%m/%d/%Y", localtime(&currentTime));

    // vector<std::string> dateBreakdown;
    // std::string tempString = "";
    // for (int i = 0; i < sizeLimit; i++) {
    //     if (formattedTime[i] == '/') {
    //         dateBreakdown.push_back(tempString);
    //         tempString = "";
    //     } else {
    //         tempString += formattedTime[i];
    //     }
    // }
    // dateBreakdown.push_back(tempString);

    // if(dateBreak)

    int currentMonth = 5;
    int currentYear = 2021;
    std::string lengthCVC = std::to_string(cvc);

    if ((currentYear > expiryDateYear) ||
        (currentYear == expiryDateYear && currentMonth >= expiryDateMonth) ||
        (isValid(creditCardNumber) == false) || lengthCVC.length() == 0 ||
        lengthCVC.length() > 3 || expiryDateMonth > 12 || expiryDateMonth < 0) {
        std::cout << "Invalid Credit Card!" << std::endl;
        return pay(amount);
    }

    return true;
}

CreditCard::~CreditCard() {}