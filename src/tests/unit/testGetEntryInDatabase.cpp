#include <cassert>
#include <iostream>
#include <vector>

#include "../../utils/createEntryInDatabase.h"
#include "../../utils/getEntryInDatabase.h"

int main() {
    remove("src/database/testAuth.txt");
    std::cout << "getEntryInDatabase ";

    createEntryInDatabase("abcdefgh,secondElem", "testAuth");

    // Get must-match entry that doesn't exist
    assert(getEntryInDatabase("sdhfbgeirunb", "testAuth", false).empty() == true);

    // Get non must-match entry that doesn't exist
    assert(getEntryInDatabase("9999999", "testAuth", true).empty() == true);

    // Get must-match entry that exists
    std::vector<std::string> testVector = {"abcdefgh", "secondElem"};
    assert(getEntryInDatabase("abcdefgh,secondElem", "testAuth", true) == testVector);

    // Get non must-match entry that exists
    assert(getEntryInDatabase("abc", "testAuth", false) == testVector);

    remove("src/database/testAuth.txt");

    std::cout << " - Passed" << std::endl;
};