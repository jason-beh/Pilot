#include <iostream>
#include <cassert>

#include "../../classes/OnlineBanking.h"
#include "../../utils/createEntryInDatabase.h"
#include "../../utils/updateEntryInDatabase.h"

/**
 * Test OnlineBanking pay
 * 
 * @param
 * @return
 */
int main() {
    OnlineBanking* onlineBanking = new OnlineBanking();
    bool isTopUpSuccessful = onlineBanking->pay(10);
    assert(isTopUpSuccessful = true);

    delete onlineBanking;
    onlineBanking = nullptr;
}