#include "User.h"

#include "../utils/createEntryInDatabase.h"
#include "../utils/getEntryInDatabase.h"

#include <fstream>
#include <string>
#include <iostream>

User::User() {
    isLoggedIn = false;
    username = "";
    password = "";
}

std::string User::getUsername() {
    return username;
}

bool User::getIsLoggedIn() {
    return isLoggedIn;
};

void User::setIsLoggedIn(bool isLoggedInStatus) {
    isLoggedIn = isLoggedInStatus;
};

void User::setUsername(std::string newUsername) {
    username = newUsername;
};
void User::setPassword(std::string newPassword) {
    password = newPassword;
};

bool User::signUp(std::string userType) {
    // Get all relevant details
    std::cout << "-----------------------" << std::endl;
    std::cout << "Sign up as " << userType << std::endl;
    std::cout << "-----------------------" << std::endl;

    bool isAccountExist = false;
    bool isPasswordsMatch = true;

    do {
        // Get relevant details for signup
        std::string username;
        std::cout << "Username: ";
        std::cin >> username;

        std::string password;
        std::cout << "Password: ";
        std::cin >> password;

        std::string confirmPassword;
        std::cout << "Confirm Password: ";
        std::cin >> confirmPassword;

        // Restart the loop if the passwords don't match
        isPasswordsMatch = (confirmPassword == password);
        if(isPasswordsMatch == false) {
            std::cout << std::endl << "The passwords don't match" << std::endl << std::endl;
            continue;
        } 

        // Checking if user exists
        isAccountExist = false;
        std::string currentLine;
        std::string databasePath = "src/database/auth" + userType + ".txt";
        std::ifstream fileStream(databasePath);

        // Read the entire file line by line
        while (getline(fileStream, currentLine)) {
            // Break the while loop if the current line's username matches
            if (currentLine.substr(0, currentLine.find(",")) == username) {
                isAccountExist = true;
                break;
            }
        }

        // Close file stream
        fileStream.close();

        // Restart the loop if account exists
        if (isAccountExist == true) {
            std::cout << std::endl << "Username is taken" << std::endl << std::endl;
            continue;
        }

    } while(isAccountExist == true || isPasswordsMatch == false);

    // Set new username, password and isLoggedInStatus
    setUsername(username);
    setPassword(password);
    setIsLoggedIn(true);

    // Create new entry in database
    std::string databaseEntry = username + "," + password;
    createEntryInDatabase(databaseEntry, "auth" + userType);

    return true;
};
bool User::login(std::string userType) {
    std::cout << "-----------------------" << std::endl;
    std::cout << "Login as " << userType << std::endl;
    std::cout << "-----------------------" << std::endl;

    bool isAuthenticated = false;

    std::string username;
    std::string password;

    do {
        username = "";
        std::cout << "Username: ";
        std::cin >> username;

        password = "";
        std::cout << "Password: ";
        std::cin >> password;
        std::cout << std::endl;

        // Search entry in database
        std::string databaseEntry = username + "," + password;
        // isAuthenticated = getEntryInDatabase(databaseEntry, "auth" + userType);

        if(isAuthenticated == false) {
            std::cout << "Incorrect login details or Account doesn't exists" << std::endl << std::endl;
        }
    } while(isAuthenticated == false);

    // Update state as user is now logged in
    setUsername(username);
    setPassword(password);
    setIsLoggedIn(true);

    std::cout << "Login successfully!" << std::endl;

    return true;
};

User::~User() {}