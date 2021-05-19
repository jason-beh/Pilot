#include "User.h"

#include "../utils/createEntryInDatabase.h"
#include "../utils/getEntryInDatabase.h"

#include <fstream>
#include <string>
#include <iostream>
#include <vector>

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

    std::vector<std::string> userAccount = {};
    bool isPasswordsMatch = true;

    std::string username;
    std::string password;
    std::string confirmPassword;

    do {
        // Get relevant details for signup
        username = "";
        std::cout << "Username: ";
        std::cin >> username;

        password = "";
        std::cout << "Password: ";
        std::cin >> password;

        confirmPassword = "";
        std::cout << "Confirm Password: ";
        std::cin >> confirmPassword;

        // Restart the loop if the passwords don't match
        isPasswordsMatch = (confirmPassword == password);
        if(isPasswordsMatch == false) {
            std::cout << std::endl << "The passwords don't match" << std::endl << std::endl;
            continue;
        } 

        // Checking if user exists
        std::string databaseEntry = username;
        userAccount = getEntryInDatabase(username, "auth" + userType, false);

        if(userAccount.empty() == false && userAccount[0] == username) {
            std::cout << std::endl << "Username is taken" << std::endl << std::endl;
            continue;
        }
    } while(userAccount.empty() == false || isPasswordsMatch == false);

    // Set new username, password and isLoggedInStatus
    setUsername(username);
    setPassword(password);
    setIsLoggedIn(true);

    std::cout << "Sign up successfully!" << std::endl;

    // Create new entry in database
    std::string databaseEntry = username + "," + password;
    createEntryInDatabase(databaseEntry, "auth" + userType);

    return true;
};
bool User::login(std::string userType) {
    std::cout << "-----------------------" << std::endl;
    std::cout << "Login as " << userType << std::endl;
    std::cout << "-----------------------" << std::endl;

    std::vector<std::string> userAccount;

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
        userAccount = getEntryInDatabase(databaseEntry, "auth" + userType, true);

        if(userAccount.empty() == true) {
            std::cout << "Incorrect login details or Account doesn't exists" << std::endl << std::endl;
        }
    } while(userAccount.empty() == true);

    // Update state as user is now logged in
    setUsername(username);
    setPassword(password);
    setIsLoggedIn(true);

    std::cout << "Login successfully!" << std::endl;

    return true;
};

User::~User() {}