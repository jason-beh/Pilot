#include <string>
#include <fstream>
#include <iostream>
#include "createEntryInDatabase.h"

/**
 * Create entry in the text database file
 * @param std::string databaseEntry (The exact line to be inserted into the text file e.g., example,1234) 
 * @param std::string databaseName (The exact file name without the .txt extension)
 * @return bool state (true if the entry is made into the database, false if the entry is not made into the database)
 */
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