#include <iostream>

#include "../../controllers/authController.h"
#include "../../utils/createEntryInDatabase.h"
#include "../../utils/updateEntryInDatabase.h"

/**
 * Test login and exit the program
 * 
 * @param
 * @return
 */
int main() {
    createEntryInDatabase("test,10005", "authRider");
    authController();

    updateEntryInDatabase("test,10005", "authRider", "", true);
    updateEntryInDatabase("test,0", "balanceRider", "", true);
}