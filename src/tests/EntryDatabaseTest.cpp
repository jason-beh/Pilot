#include <iostream>

#include "../utils/createEntryInDatabase.h"
#include "../utils/searchEntryInDatabase.h"

int main()
{
    assert(searchEntryInDatabase("abc", "testAuth") == false);

    createEntryInDatabase("abcdefgh", "testAuth");

    assert(searchEntryInDatabase("abcdefgh", "testAuth") == true);
}