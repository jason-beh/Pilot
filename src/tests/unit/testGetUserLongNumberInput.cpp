#include <iostream>

#include "../../utils/getUserLongNumberInput.h"

/**
 * Test getUserLongNumberInput
 * 
 * @param
 * @return
 */
int main() {
    getUserLongNumberInput("Enter your decision here: ");

    std::cout << std::endl << "getUserLongNumberInput ";
    std::cout << " - Passed" << std::endl;
}