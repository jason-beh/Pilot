#include "getUserStringInput.h"

#include <iostream>
#include <string>
#include <limits>
#include <sstream>

std::string getUserStringInput(std::string instruction, bool isFirstPrompt) {
    bool prompt = true;
    std::string finalString = "";

    bool hasIgnored = false;

    // While loop to prompt users for decision forever
    while (prompt) {
        std::cout << instruction;

        std::cin >> finalString;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // if(isFirstPrompt == true) {
        //     std::cin.ignore();
        // }

        // if(isFirstPrompt == true && hasIgnored == false) {
        //     std::cin.ignore();
        //     hasIgnored = true;
        // }

        // std::getline(std::cin, finalString);

        // std::cin >> finalString;
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // bool containsWhitespace = false;

        // for(int i = 0; i < finalString.size(); i++) {
        //     if(isspace(finalString[i]) == true) {
        //         containsWhitespace = true;
        //     } 
        // }

        if (finalString.find(",") != std::string::npos) {
            std::cout << "Input must not contain ',' or whitespace" << std::endl;
            prompt = true;
        } else {
            prompt = false;
        }
    }

    return finalString;
}