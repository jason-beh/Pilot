#include <iostream>

#include "../utils/generateUserOptions.h"

int main() {
    // 5 inputs
    generateUserOptions(5);

    // 0 inputs
    generateUserOptions(0);

    // 1 input
    generateUserOptions(1);

    std::cout << std::endl << "generateUserOptions ";
    std::cout << " - Passed" << std::endl;
}