#include <iostream>
#include <cassert>
#include <vector>

#include "../../utils/createEntryInDatabase.h"
#include "../../utils/getEntryInDatabase.h"

/**
 * Test create entry in mock database
 * 
 * @param
 * @return
 */
int main() {
    remove("src/database/testAuth.txt");

    std::cout << "createEntryInDatabase ";

    // Create entry in non-existant database
    createEntryInDatabase("Jane,testEntry2", "testAuth");
    std::vector<std::string> testVector = {"Jane", "testEntry2"};
    assert(getEntryInDatabase("Jane,testEntry2", "testAuth", true) == testVector);

    // Create entry in existant databases
    createEntryInDatabase("Bob,testEntry4", "testAuth");
    testVector = {"Bob", "testEntry4"};
    assert(getEntryInDatabase("Bob,testEntry4", "testAuth", true) == testVector);

    remove("src/database/testAuth.txt");
    std::cout << " - Passed" << std::endl;
};