#include "getUserNumberedInput.h"

#include <iostream>
#include <string>

int getUserNumberedInput(int numOptions) {
    bool prompt = true;
    int optionChosen;

    // While loop to prompt users for decision forever
    while (prompt) {
        std::cout << "Enter decision: ";

        // Check if input is a valid number and between the range from 1 to numOptions
        if (std::cin >> optionChosen) {
            if (optionChosen >= 1 && optionChosen <= numOptions) {
                prompt = false;
                break;
            }
        }

        // Otherwise, print error message for valid input
        std::string errorMessage = "Please enter ";
        for (int i = 1; i <= numOptions; i++) {
            if (i == numOptions) {
                errorMessage += " or ";
            } else if (i > 1) {
                errorMessage += ", ";
            }
            errorMessage += std::to_string(i);
        }
        errorMessage += " only";
        std::cout << errorMessage << std::endl;

        // Clear input and reset
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return optionChosen;
}