#include <iostream>

#include "../../controllers/authController.h"
#include "../../utils/createEntryInDatabase.h"
#include "../../utils/updateEntryInDatabase.h"

int main() {
    createEntryInDatabase("test,10005", "authDriver");
    authController();

    updateEntryInDatabase("test,10005", "authDriver", "", true);
    updateEntryInDatabase("test,0", "balanceDriver", "", true);
}