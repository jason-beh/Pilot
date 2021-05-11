#include <iostream>
#include <stdio.h>

#include "../utils/createEntryInDatabase.h"
#include "../utils/searchEntryInDatabase.h"

int main()
{
    // Find "abc" in testAuth(file will be created on the fly)
    assert(searchEntryInDatabase("abc", "testAuth") == false);

    // Create "abcdefgh" to test
    createEntryInDatabase("abcdefgh", "testAuth");

    // Search "abcdefgh"
    assert(searchEntryInDatabase("abcdefgh", "testAuth") == true);

    // Delete testAuth before ending test. 
    // Terminate if there is an error
    if (remove("src/database/testAuth.txt") != 0) {
        std::cout << "Error deleting file" << std::endl;
        return -1;
    }
}