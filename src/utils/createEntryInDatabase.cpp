#include <string>
#include <fstream>
#include <iostream>
#include "createEntryInDatabase.h"

void createEntryInDatabase(std::string databaseEntry, std::string databaseName)
{
    std::ofstream fileStream;
    std::string databasePath = "src/databasee/" + databaseName + ".txt";

    // std::cout << "FileStream: " << databasePath << std::endl;

    // Open file for append only
    fileStream.open(databasePath, std::ios::app);

    // Add a new entry to the file with newline
    fileStream << databaseEntry << "\n";

    // Close file stream
    fileStream.close();
};