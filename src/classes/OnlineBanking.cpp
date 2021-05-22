#include "OnlineBanking.h"

#include <unistd.h>

#include <iostream>
#include <string>

#include "../utils/generateUserOptions.h"

using namespace std;

OnlineBanking::OnlineBanking() {}

bool OnlineBanking::pay(int amount) {
    // Prompt user to choose type of bank
    std::cout << "Please choose the your preferred bank from the list below."
              << std::endl;

    std::cout << "1. Commonwealth Bank" << std::endl;
    std::cout << "2. ANZ Bank" << std::endl;
    std::cout << "3. Westpac Bank" << std::endl;
    std::cout << "4. Bank of Queensland" << std::endl;
    std::cout << "5. National Australia Bank" << std::endl;

    generateUserOptions(5);

    // Countdown to simluate to a third party API
    std::cout << "Redirecting you to the bank you have chosen..." << std::endl
              << std::endl;

    int seconds = 7;
    while (seconds > 0) {
        std::cout << seconds-- << std::endl;
        sleep(1);
    }

    std::cout << std::endl << "Topped up AUD" << amount << " successfully!" << std::endl;

    return true;
}

OnlineBanking::~OnlineBanking() {}