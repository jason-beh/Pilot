#include <iostream>
#include <cassert>

#include "../../classes/AccountBalance.h"

int main() {
    AccountBalance* accountBalance = new AccountBalance();
    bool isTopUpSuccessful = accountBalance->pay(10);
    assert(isTopUpSuccessful = true);

    delete accountBalance;
    accountBalance = nullptr;
}