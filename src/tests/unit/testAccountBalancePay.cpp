#include <iostream>
#include <cassert>

#include "../../classes/AccountBalance.h"

/**
 * Test AccountBalance pay
 * 
 * @param
 * @return
 */
int main() {
    AccountBalance* accountBalance = new AccountBalance();
    bool isTopUpSuccessful = accountBalance->pay(10);
    assert(isTopUpSuccessful = true);

    delete accountBalance;
    accountBalance = nullptr;
}