#include <iostream>

#include "../utils/getUserNumberInput.h"

int main() {
    getUserNumberInput("Enter your decision here: ");

    std::cout << std::endl << "getUserNumberInput ";
    std::cout << " - Passed" << std::endl;
}