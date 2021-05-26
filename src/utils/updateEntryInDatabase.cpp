#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdio>
#include <cstring>

#include "updateEntryInDatabase.h"

/**
 * Retrieve a vector of the split entry based on the search database query
 * 
 * @param std::string databaseEntry (The database search entry to match with the data in the database)
 * @param std::string databaseName (The exact file name without the .txt extension)
 * @param std::string newDatabaseEntry (The new database entry that will replace the matched search entry, if the searched entry is found)
 * @param bool mustSearchMatch (true means the searchEntry must match the current entry of database to return as vector, false means substring is accepted to return as vector)
 * @return std::vector<std::string> (databaseEntry that is split by "," into a vector)
 */
bool updateEntryInDatabase(std::string databaseEntry, std::string databaseName, std::string newDatabaseEntry, bool mustSearchMatch)
{
    std::string currentLine;
    std::string databasePath = "src/database/" + databaseName + ".txt";
    std::ifstream inFileStream(databasePath);

    std::string newDatabasePath = "src/database/" + databaseName + "New" + ".txt";
    std::ofstream outFileStream(newDatabasePath);

    // Read the entire file line by line
    while (getline(inFileStream, currentLine))
    {
        if(mustSearchMatch == false) {
            if (currentLine.find(databaseEntry) != std::string::npos) {
                currentLine = newDatabaseEntry;
            }
        } else {
            if (currentLine == databaseEntry) {
                currentLine = newDatabaseEntry;
            }
        }

        outFileStream << currentLine;

        if(currentLine != "") {
            outFileStream << '\n';
        }

        
    }

    // Convert strings into char[]
    char charDatabasePath[databasePath.length() + 1];
    char charNewDatabasePath[newDatabasePath.length() + 1];
    strcpy(charDatabasePath, databasePath.c_str());
    strcpy(charNewDatabasePath, newDatabasePath.c_str());

    if (remove(charDatabasePath) != 0) {
        std::cout << "Error deleting old file" << std::endl;
        return false;
    }

    if (rename(charNewDatabasePath, charDatabasePath) != 0) {
        std::cout << "Error renaming old file to new file" << std::endl;
        return false;
    }
		
    // Close file stream
    inFileStream.close();
    outFileStream.close();

    return true;
};