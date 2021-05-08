#include <string>
#include <fstream>
#include <iostream>
#include "searchEntryInDatabase.h"

bool searchEntryInDatabase(std::string databaseEntry, std::string databaseName)
{
    std::string currentLine;
    bool isEntryFound = false;
    std::string databasePath = "src/database/" + databaseName + ".txt";
    std::ifstream fileStream(databasePath);

    // Read the entire file line by line
    while (getline(fileStream, currentLine))
    {
        // Break the while loop if the current line contains databaseEntry
        if (currentLine.find(databaseEntry) != std::string::npos)
        {
            isEntryFound = true;
            break;
        }
    }

    // Close file stream
    fileStream.close();

    return isEntryFound;
};