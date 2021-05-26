#include <iostream>

#include "../../utils/getUserNumberInput.h"

/**
 * Test getUserNumberInput
 * 
 * @param
 * @return
 */
int main() {
    getUserNumberInput("Enter your decision here: ");

    std::cout << std::endl << "getUserNumberInput ";
    std::cout << " - Passed" << std::endl;
}