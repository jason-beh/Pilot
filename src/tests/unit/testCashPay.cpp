#include <iostream>
#include <cassert>

#include "../../classes/Cash.h"

/**
 * Test Cash pay
 * 
 * @param
 * @return
 */
int main() {
    Cash* cash = new Cash();
    bool isTopUpSuccessful = cash->pay(10);
    assert(isTopUpSuccessful = true);

    delete cash;
    cash = nullptr;
}