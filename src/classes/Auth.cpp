#include "Auth.h"
#include "../utils/createEntryInDatabase.h"
#include "../utils/searchEntryInDatabase.h"

#include <fstream>
#include <string>
#include <iostream>

Auth::Auth()
{
    authUsername = "";
    authPassword = "";
    isLoggedIn = false;
}

void Auth::setAuthUsername(std::string username)
{
    authUsername = username;
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

bool Auth::signUp(std::string userType)
{
    // Get all relevant details

    std::cout << "-----------------------" << std::endl;
    std::cout << "Sign up as " << userType << std::endl;
    std::cout << "-----------------------" << std::endl;

    std::string username;
    std::cout << "Username: ";
    std::cin >> username;

    std::string password;
    std::cout << "Password: ";
    std::cin >> password;

    std::string confirmPassword;
    std::cout << "Confirm Password: ";
    std::cin >> confirmPassword;

    if(confirmPassword != password) {
        std::cout << "The passwords don't match" << std::endl;
        return signUp(userType);
    } 

    bool isAccountExist = false;

    std::string currentLine;
    std::string databasePath = "src/database/auth" + userType + ".txt";
    std::ifstream fileStream(databasePath);

    // Read the entire file line by line
    while (getline(fileStream, currentLine)) {
        // Break the while loop if the current line contains databaseEntry
        if (currentLine.substr(0, currentLine.find(",")) == username) {
            isAccountExist = true;
            break;
        }
    }

    // Close file stream
    fileStream.close();

    // Terminate the function if account exist
    if (isAccountExist == true) {
        std::cout << "Username is taken" << std::endl;
        return signUp(userType);
    }

    // Set new username, password and isLoggedInStatus
    setAuthUsername(username);
    setAuthPassword(password);
    setIsLoggedIn(true);

    // Create new entry in database
    std::string databaseEntry = username + "," + password;
    createEntryInDatabase(databaseEntry, "auth" + userType);

    return true;
}

bool Auth::login(std::string userType)
{
    std::cout << "-----------------------" << std::endl;
    std::cout << "Login as " << userType << std::endl;
    std::cout << "-----------------------" << std::endl;

    std::string username;
    std::cout << "Username: ";
    std::cin >> username;

    std::string password;
    std::cout << "Password: ";
    std::cin >> password;
    std::cout << std::endl;

    // Search entry in database
    std::string databaseEntry = username + "," + password;
    bool isAuthenticated = searchEntryInDatabase(databaseEntry, "auth" + userType);

    if (isAuthenticated == true) {
        std::cout << "Login successfully!" << std::endl;
        setAuthUsername(username);
        setAuthPassword(password);
        setIsLoggedIn(true);
        return true;
    }

    std::cout << "Incorrect user details / account doesn't exists" << std::endl;
    return login(userType);
}

Auth::~Auth() {}