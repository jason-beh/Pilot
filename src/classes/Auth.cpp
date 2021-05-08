#include "Auth.h"
#include "../utils/createEntryInDatabase.h"
#include "../utils/searchEntryInDatabase.h"

#include <string>

Auth::Auth()
{
    authEmail = "";
    authPassword = "";
    isLoggedIn = false;
}

void Auth::setAuthEmail(std::string email)
{
    authEmail = email;
};

void Auth::setAuthPassword(std::string password)
{
    authPassword = password;
};

void Auth::setIsLoggedIn(bool isLoggedInStatus)
{
    isLoggedIn = isLoggedInStatus;
};

bool Auth::getIsLoggedIn()
{
    return isLoggedIn;
}

bool Auth::signUp(std::string email, std::string password)
{
    bool isAccountExist = searchEntryInDatabase(email, "auth");

    // Terminate the function if account exist
    if (isAccountExist)
    {
        return false;
    }

    // Set new email, password and isLoggedInStatus
    setAuthEmail(email);
    setAuthPassword(password);
    setIsLoggedIn(true);

    // Create new entry in database
    std::string databaseEntry = email + "," + password;
    createEntryInDatabase(databaseEntry, "auth");

    return true;
}

bool Auth::login(std::string email, std::string password)
{
    // Search entry in database
    std::string databaseEntry = email + "," + password;
    bool isAuthenticated = searchEntryInDatabase(databaseEntry, "auth");

    if (isAuthenticated)
    {
        setAuthEmail(email);
        setAuthPassword(password);
        setIsLoggedIn(true);
        return true;
    }

    return false;
}

Auth::~Auth() {}