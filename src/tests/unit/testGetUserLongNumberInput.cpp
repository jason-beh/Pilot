#include <iostream>

#include "../../utils/getUserLongNumberInput.h"

int main() {
    getUserLongNumberInput("Enter your decision here: ");

    std::cout << std::endl << "getUserLongNumberInput ";
    std::cout << " - Passed" << std::endl;
}