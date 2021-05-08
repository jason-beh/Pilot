#include <string>
#include <fstream>
#include <iostream>
#include "createEntryInDatabase.h"

bool createEntryInDatabase(std::string databaseEntry, std::string databaseName) {
  std::ofstream outfile;

  std::string databasePath = "src/database/" + databaseName + ".txt";

  outfile.open(databasePath, std::ios_base::app);
  outfile << databaseEntry; 
  return true;
};