#include <iostream>

#include "../../utils/getUserStringInput.h"

/**
 * Test getUserStringInput
 * 
 * @param
 * @return
 */
int main() {
    // std::cin.ignore();
    getUserStringInput("Enter your decision here: ", true);

    std::cout << std::endl << "getUserStringInput ";
    std::cout << " - Passed" << std::endl;
}