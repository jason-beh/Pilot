#include "User.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../utils/createEntryInDatabase.h"
#include "../utils/getEntryInDatabase.h"
#include "../utils/getUserStringInput.h"
#include "../utils/updateEntryInDatabase.h"

User::User() {
    isLoggedIn = false;
    username = "";
    password = "";
    currentBalance = 0;
}

std::string User::getUsername() { return username; }

bool User::getIsLoggedIn() { return isLoggedIn; };

void User::setIsLoggedIn(bool isLoggedInStatus) {
    isLoggedIn = isLoggedInStatus;
};

void User::setUsername(std::string newUsername) { username = newUsername; };
void User::setPassword(std::string newPassword) { password = newPassword; };

bool User::signUp(std::string userType) {
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
        username = getUserStringInput("Username: ", true);
        password = getUserStringInput("Password: ", true);
        confirmPassword = getUserStringInput("Confirm Password: ", false);

        // Restart the loop if the passwords don't match
        isPasswordsMatch = (confirmPassword == password);
        if (isPasswordsMatch == false) {
            std::cout << std::endl
                      << "The passwords don't match" << std::endl
                      << std::endl;
            continue;
        }

        // Checking if user exists
        std::string databaseEntry = username;
        userAccount = getEntryInDatabase(username, "auth" + userType, false);

        if (userAccount.empty() == false && userAccount[0] == username) {
            std::cout << std::endl
                      << "Username is taken" << std::endl
                      << std::endl;
            continue;
        }
    } while (userAccount.empty() == false || isPasswordsMatch == false);

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
        // Get relevant details for login
        username = getUserStringInput("Username: ", true);
        password = getUserStringInput("Password: ", false);

        std::cout << username << std::endl;
        std::cout << password << std::endl;

        // Search entry in database
        std::string databaseEntry = username + "," + password;
        userAccount =
            getEntryInDatabase(databaseEntry, "auth" + userType, true);

        if (userAccount.empty() == true) {
            std::cout << "Incorrect login details or Account doesn't exists"
                      << std::endl
                      << std::endl;
        }
    } while (userAccount.empty() == true);

    // Update state as user is now logged in
    setUsername(username);
    setPassword(password);
    setIsLoggedIn(true);

    std::cout << "Login successfully!" << std::endl;

    return true;
};

void User::setCurrentBalance(int amount, std::string databaseName) {
    std::string username = getUsername();
    std::string newDatabaseEntry = username + "," + std::to_string(amount);

    // Update user's current balance in database
    updateEntryInDatabase(username, databaseName, newDatabaseEntry, false);

    // Update user object's current balance
    currentBalance = amount;
}

int User::getCurrentBalance(std::string databaseName) {
    // Perform database check if the current balance is 0 (Suitable when initialized)
    if (currentBalance == 0) {
        std::string username = getUsername();

        std::vector<std::string> databaseResults =
            getEntryInDatabase(username, databaseName, false);

        // If user is just created, create new entry in current balance database
        // Else retrieve user current balance from database
        if (databaseResults.empty() == false &&
            databaseResults[0] == username) {
            std::string balance = databaseResults[1];
            setCurrentBalance(stoi(balance), databaseName);
            return stoi(balance);
        } else {
            std::string newDatabaseEntry = username + ",0";
            createEntryInDatabase(newDatabaseEntry, databaseName);
            return 0;
        }
    }

    return currentBalance;
}

User::~User() {}