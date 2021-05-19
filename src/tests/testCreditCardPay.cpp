#include <iostream>
#include <cassert>

#include "../classes/CreditCard.h"
#include "../utils/createEntryInDatabase.h"
#include "../utils/updateEntryInDatabase.h"

int main() {
    CreditCard* creditCard = new CreditCard();
    bool isTopUpSuccessful = creditCard->pay(10);
    assert(isTopUpSuccessful = true);

    delete creditCard;
    creditCard = nullptr;
}