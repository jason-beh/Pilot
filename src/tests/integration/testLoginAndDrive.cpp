#include <iostream>

#include "../../controllers/authController.h"
#include "../../utils/createEntryInDatabase.h"
#include "../../utils/updateEntryInDatabase.h"

/**
 * Test login and drive
 * 
 * @param
 * @return
 */
int main() {
    createEntryInDatabase("test,10005", "authDriver");
    authController();

    updateEntryInDatabase("test,10005", "authDriver", "", true);
    updateEntryInDatabase("test,0", "balanceDriver", "", true);
}