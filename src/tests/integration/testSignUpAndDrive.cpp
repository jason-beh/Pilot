#include <iostream>

#include "../../controllers/authController.h"
#include "../../utils/createEntryInDatabase.h"
#include "../../utils/updateEntryInDatabase.h"

/**
 * Test sign up and drive
 * 
 * @param
 * @return
 */
int main() {
    authController();

    updateEntryInDatabase("test,10005", "authDriver", "", true);
    updateEntryInDatabase("test,0", "balanceDriver", "", true);
}