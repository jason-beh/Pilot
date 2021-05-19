#include "scripts/testGetEntryInDatabase.h"
#include "scripts/testCreateEntryInDatabase.h"
#include "scripts/testUpdateEntryInDatabase.h"

#include <iostream>

int main() {
    std::cout << std::endl << "RUNNING NON-INPUT TESTS" << std::endl << std::endl;

    testGetEntryInDatabase();
    testCreateEntryInDatabase();
    testUpdateEntryInDatabase();

    std::cout << std::endl << "All tests cases are successful!" << std::endl;
}