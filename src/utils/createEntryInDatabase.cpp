#include <string>
#include <fstream>
#include <iostream>
#include "createEntryInDatabase.h"

bool createEntryInDatabase(std::string databaseEntry, std::string databaseName)
{
    std::string databasePath = "src/database/" + databaseName + ".txt";

    // Open file for append only
    std::ofstream fileStream(databasePath, std::ios::app);
    
    // Return false if there is an error
    if(!fileStream) {
        return false;
    }

    // Add a new entry to the file with newline
    fileStream << databaseEntry << "\n";

    // Close file stream
    fileStream.close();

    return true;
};