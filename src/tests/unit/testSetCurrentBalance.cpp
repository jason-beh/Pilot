#include <iostream>
#include <cassert>

#include "../../classes/Rider.h"
#include "../../utils/createEntryInDatabase.h"
#include "../../utils/updateEntryInDatabase.h"

int main() {
    createEntryInDatabase("test,10005", "authRider");

    Rider* rider = new Rider();

    rider->login("Rider");

    int currentBalance = rider->getCurrentBalance();
    assert(currentBalance == 0);

    rider->setCurrentBalance(10);
    currentBalance = rider->getCurrentBalance();
    assert(currentBalance == 10);
    
    delete rider;
    rider = nullptr;

    updateEntryInDatabase("test,10005", "authRider", "", true);
    updateEntryInDatabase("test,10", "balanceRider", "", true);
}