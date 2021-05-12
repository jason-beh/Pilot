#include "OnlineBanking.h"
#include "../utils/generateUserOptions.h"
#include "../utils/countdownTimer.h"

#include <string>
#include <iostream>

using namespace std;

OnlineBanking::OnlineBanking() {
}

bool OnlineBanking::pay(int amount) {
    std::cout << std::endl;
    std::cout << "Please choose the your preferred bank from the list below." << std::endl;

    std::cout << "1. Commonwealth Bank" << std::endl;
    std::cout << "2. ANZ Bank" << std::endl;
    std::cout << "3. Westpac Bank" << std::endl;
    std::cout << "4. Bank of Queensland" << std::endl;
    std::cout << "5. National Australia Bank" << std::endl << std::endl;

    int option = generateUserOptions(5);

    std::cout << std::endl;
    std::cout << "Redirecting you to the bank you have chosen..." << std::endl << std::endl;;

    countdownTimer(8);
    
    std::cout << "Topped up AUD" << amount << " successfully!" << std::endl;


    return true;
}

OnlineBanking::~OnlineBanking() {}