#ifndef AUTH_H
#define AUTH_H

#include <string>

class Auth
{
private:
    Auth();

    std::string authEmail;
    std::string authPassword;
    bool isLoggedIn;

    void setAuthEmail(std::string email);
    void setAuthPassword(std::string password);
    void setIsLoggedIn(bool isLoggedInStatus);

    bool getIsLoggedIn();

    bool signUp(std::string email, std::string password);
    bool login(std::string email, std::string password);

    ~Auth();
};

#endif