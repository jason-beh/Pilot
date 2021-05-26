#include "splitString.h"
#include <vector>
#include <string>

/**
 * Split string based on delimeter
 * 
 * @param std::string inputString (Input string of the sentence)
 * @param std::string delimiter (Delimiter to split the string into vector of strings)
 * @return std::vector<std::string> data (Split string based on delimeter in vector form)
 */
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