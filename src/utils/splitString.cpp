#include "splitString.h"
#include <vector>
#include <string>

std::vector<std::string> splitString(std::string inputString, std::string delimiter) {
    std::vector<std::string> splitArray = {};

    if (inputString != "") {
        int pos = 0;
        std::string token;

        while ((pos = inputString.find(delimiter)) != std::string::npos) {
            token = inputString.substr(0, pos);
            splitArray.push_back(token);
            inputString.erase(0, pos + delimiter.length());
        }

        splitArray.push_back(inputString);
    }

    return splitArray;
}