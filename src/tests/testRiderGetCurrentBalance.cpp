#include <iostream>

#include "../classes/Rider.h"
#include "../utils/createEntryInDatabase.h"
#include "../utils/updateEntryInDatabase.h"

int main() {
    createEntryInDatabase("test,10005", "authRider");

    Rider* rider = new Rider();

    rider->login("Rider");

    int currentBalance = rider->getCurrentBalance();
    std::cout << currentBalance << std::endl;

    delete rider;
    rider = nullptr;

    updateEntryInDatabase("test,10005", "authRider", "", true);
    updateEntryInDatabase("test,0", "balanceRider", "", true);
}