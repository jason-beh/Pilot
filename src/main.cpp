#include <iostream>

#include "controllers/AuthController.h"
#include "controllers/RiderController.h"

#include "utils/createEntryInDatabase.h"
#include "utils/searchEntryInDatabase.h"
#include "utils/generateUserOptions.h"
#include "utils/countdownTimer.h"

#include "classes/Auth.h"
#include "classes/User.h"
#include "classes/Driver.h"
#include "classes/Rider.h"

int main()
{  
    AuthController();

    // Rider* rider = new Rider();

    // rider->topUp(50);

    // RiderController(rider);
}
