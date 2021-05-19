#include <iostream>
#include <cassert>

#include "../classes/OnlineBanking.h"
#include "../utils/createEntryInDatabase.h"
#include "../utils/updateEntryInDatabase.h"

int main() {
    OnlineBanking* onlineBanking = new OnlineBanking();
    bool isTopUpSuccessful = onlineBanking->pay(10);
    assert(isTopUpSuccessful = true);

    delete onlineBanking;
    onlineBanking = nullptr;
}