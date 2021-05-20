#include <iostream>

#include "../utils/getUserStringInput.h"

int main() {
    // std::cin.ignore();
    getUserStringInput("Enter your decision here: ", true);

    std::cout << std::endl << "getUserStringInput ";
    std::cout << " - Passed" << std::endl;
}