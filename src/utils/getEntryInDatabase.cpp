#include "getEntryInDatabase.h"
#include "splitString.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/**
 * Retrieve a vector of the split entry based on the search database query
 * 
 * @param std::string searchEntry (The search entry to match with the data in the database)
 * @param std::string databaseName (The exact file name without the .txt extension)
 * @param bool mustSearchMatch (true means the searchEntry must match the current entry of database to return as vector, false means substring is accepted to return as vector)
 * @return std::vector<std::string> (databaseEntry that is split by "," into a vector)
 */
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