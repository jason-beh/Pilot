#include <iostream>
#include <cassert>

#include "../../classes/Cash.h"

int main() {
    Cash* cash = new Cash();
    bool isTopUpSuccessful = cash->pay(10);
    assert(isTopUpSuccessful = true);

    delete cash;
    cash = nullptr;
}