#include <iostream>
#include <cassert>
#include <vector>

#include "../../utils/createEntryInDatabase.h"
#include "../../utils/updateEntryInDatabase.h"
#include "../../utils/getEntryInDatabase.h"

/**
 * Test updateEntryInDatabase
 * 
 * @param
 * @return
 */
int main() {
    remove("src/database/testAuth.txt");

    std::cout << "updateEntryInDatabase ";

    createEntryInDatabase("Jennifer,59", "testAuth");

    // Update must-match entry
    std::vector<std::string> testVector = {"Stephanie", "90"};
    assert(updateEntryInDatabase("Jennifer,59", "testAuth", "Stephanie,90", true) == true);
    assert(getEntryInDatabase("Stephanie,90", "testAuth", true) == testVector);
    assert(getEntryInDatabase("Jennifer,59", "testAuth", true).empty() == true);

    // Update non must-match entry
    testVector = {"Alexander", "11"};
    assert(updateEntryInDatabase("Steph", "testAuth", "Alexander,11", false) == true);
    assert(getEntryInDatabase("Alexander,11", "testAuth", true) == testVector);
    assert(getEntryInDatabase("Stephanie,90", "testAuth", true).empty() == true);

    remove("src/database/testAuth.txt");
    std::cout << " - Passed" << std::endl;
};