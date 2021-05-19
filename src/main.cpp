#include <iostream>
#include <string>

#include "controllers/authController.h"
#include "controllers/riderController.h"

#include "utils/createEntryInDatabase.h"
#include "utils/generateUserOptions.h"

#include "classes/User.h"
#include "classes/Driver.h"
#include "classes/Rider.h"

int main()
{  
    authController();

    // Rider* rider = new Rider();

    // rider->topUp(50);

    // riderController(rider);

    // std::string test = "2041";
    // int currentYear = stoi(test.substr(2,2));

    // std::cout << currentYear << std::endl;
}
