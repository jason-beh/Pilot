#include <iostream>

#include "../../controllers/authController.h"
#include "../../utils/createEntryInDatabase.h"
#include "../../utils/updateEntryInDatabase.h"

int main() {
    authController();

    updateEntryInDatabase("test,10005", "authRider", "", true);
    updateEntryInDatabase("test,0", "balanceRider", "", true);
}