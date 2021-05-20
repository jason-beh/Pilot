#include "OnlineBanking.h"
#include "../utils/generateUserOptions.h"

#include <unistd.h>
#include <string>
#include <iostream>

using namespace std;

OnlineBanking::OnlineBanking() {
}

bool OnlineBanking::pay(int amount) {
    std::cout << "Please choose the your preferred bank from the list below." << std::endl;

    std::cout << "1. Commonwealth Bank" << std::endl;
    std::cout << "2. ANZ Bank" << std::endl;
    std::cout << "3. Westpac Bank" << std::endl;
    std::cout << "4. Bank of Queensland" << std::endl;
    std::cout << "5. National Australia Bank" << std::endl;

    generateUserOptions(5);

    std::cout << "Redirecting you to the bank you have chosen..." << std::endl << std::endl;;

    // Countdown
    int seconds = 7;

    while(seconds > 0) {
        std::cout << seconds-- << std::endl;
        sleep(1);
    }

    std::cout << std::endl;
    
    std::cout << "Topped up AUD" << amount << " successfully!" << std::endl;


    return true;
}

OnlineBanking::~OnlineBanking() {}