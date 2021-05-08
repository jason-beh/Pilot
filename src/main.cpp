#include <iostream>

#include "controllers/AuthController.h"
#include "utils/createEntryInDatabase.h"
#include "utils/searchEntryInDatabase.h"

int main()
{
    std::cout << "Welcome to Pilot!" << std::endl;

    std::cout << AuthController() << std::endl;

    createEntryInDatabase("hello", "auth");
    std::cout << searchEntryInDatabase("hello", "auth");
}