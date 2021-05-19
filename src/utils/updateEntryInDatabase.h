#ifndef UPDATEENTRYINDATABASE_H
#define UPDATEENTRYINDATABASE_H

#include <string>
#include <vector>

bool updateEntryInDatabase(std::string databaseEntry, std::string databaseName, std::string newDatabaseEntry, bool mustSearchMatch);

#endif