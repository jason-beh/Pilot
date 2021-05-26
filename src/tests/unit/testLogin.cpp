#include <iostream>

#include "../../classes/Rider.h"
#include "../../utils/createEntryInDatabase.h"
#include "../../utils/updateEntryInDatabase.h"

/**
 * Test login
 * 
 * @param
 * @return
 */
int main() {
    createEntryInDatabase("test,10005", "authRider");

    Rider* rider = new Rider();

    rider->login("Rider");

    delete rider;
    rider = nullptr;

    updateEntryInDatabase("test,10005", "authRider", "", true);
}