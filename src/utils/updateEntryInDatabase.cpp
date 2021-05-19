#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdio>
#include <cstring>

#include "updateEntryInDatabase.h"

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

        outFileStream << currentLine << '\n';
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