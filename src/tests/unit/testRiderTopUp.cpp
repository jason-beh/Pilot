#include <iostream>
#include <cassert>

#include "../../classes/Rider.h"
#include "../../utils/createEntryInDatabase.h"
#include "../../utils/updateEntryInDatabase.h"

/**
 * Test Rider Top Up
 * 
 * @param
 * @return
 */
int main() {
    createEntryInDatabase("test,10005", "authRider");

    Rider* rider = new Rider();

    rider->login("Rider");

    int currentBalance = rider->getCurrentBalance();
    assert(currentBalance == 0);

    rider->topUp();

    currentBalance = rider->getCurrentBalance();
    assert(currentBalance == 100);
    
    delete rider;
    rider = nullptr;

    updateEntryInDatabase("test,10005", "authRider", "", true);
    updateEntryInDatabase("test,100", "balanceRider", "", true);
}