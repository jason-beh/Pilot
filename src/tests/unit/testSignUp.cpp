#include <iostream>

#include "../../classes/Rider.h"
#include "../../utils/createEntryInDatabase.h"
#include "../../utils/updateEntryInDatabase.h"

/**
 * Test signUp
 * 
 * @param
 * @return
 */
int main() {
    createEntryInDatabase("test,10005", "authRider");

    Rider* rider = new Rider();

    rider->signUp("Rider");

    delete rider;
    rider = nullptr;

    updateEntryInDatabase("test,10005", "authRider", "", true);
    updateEntryInDatabase("tester,1004", "authRider", "", true);
}