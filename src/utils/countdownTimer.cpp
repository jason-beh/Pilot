#include <iostream>
#include <unistd.h>

#include "countdownTimer.h"

void countdownTimer (int seconds) {
    while(seconds > 0) {
        std::cout << seconds-- << std::endl;
        sleep(1);
    }

    std::cout << std::endl;
}