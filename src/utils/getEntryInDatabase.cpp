#include "getEntryInDatabase.h"
#include "splitString.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> getEntryInDatabase(std::string searchEntry,
                                            std::string databaseName,
                                            bool mustSearchMatch = false) {
    std::string currentLine;
    std::string databasePath = "src/database/" + databaseName + ".txt";
    std::ifstream fileStream(databasePath);
    std::string databaseResult = "";

    std::vector<std::string> finalResult = {};

    // Read the entire file line by line
    while (getline(fileStream, currentLine)) {
        if (mustSearchMatch == false) {
            if (currentLine.find(searchEntry) != std::string::npos) {
                databaseResult = currentLine;
                break;
            }
        } else {
            if (currentLine == searchEntry) {
                databaseResult = currentLine;
                break;
            }
        }
    }

    finalResult = splitString(databaseResult, ",");

    // Close file stream
    fileStream.close();

    return finalResult;
};