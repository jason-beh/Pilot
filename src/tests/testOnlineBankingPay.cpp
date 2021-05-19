#include <iostream>
#include <cassert>

#include "../classes/OnlineBanking.h"
#include "../utils/createEntryInDatabase.h"
#include "../utils/updateEntryInDatabase.h"

int main() {
    OnlineBanking* onlineBankingPayment = new OnlineBanking();
    bool isTopUpSuccessful = onlineBankingPayment->pay(10);
    assert(isTopUpSuccessful = true);
}