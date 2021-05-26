#include "generateUserOptions.h"

#include <iostream>
#include <string>
#include <limits>

/**
 * Create entry in the text database file
 * @param int numOptions (Number of options to receive from 1 E.g. entering 5 means input will accept numbers from 1 until 5)
 * @return int optionChosen (The sanitized integer received from the user input)
 */
int generateUserOptions(int numOptions) {
    bool prompt = true;
    int optionChosen;

    if(numOptions <= 0) {
        return -1;
    }

    // While loop to prompt users for decision forever
    while (prompt) {
        std::cout << std::endl << "Enter decision: ";

        // Check if input is a valid number and between the range from 1 to numOptions
        if (std::cin >> optionChosen) {
            if (optionChosen >= 1 && optionChosen <= numOptions) {
                prompt = false;
                std::cout << std::endl;
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