#include "getUserNumberInput.h"

#include <iostream>
#include <string>

int getUserNumberInput() {
    bool prompt = true;
    int number;

    // While loop to prompt users for decision forever
    while (prompt) {
        std::cout << "Enter decision: ";

        if (std::cin >> number) {
            break;
        }

        // Clear input and reset
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return number;
}