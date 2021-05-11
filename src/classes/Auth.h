#ifndef AUTH_H
#define AUTH_H

#include <string>

class Auth
{
private:
    std::string authUsername;
    std::string authPassword;
    bool isLoggedIn;

    void setAuthUsername(std::string username);
    void setAuthPassword(std::string password);
    void setIsLoggedIn(bool isLoggedInStatus);

public:
    Auth();

    bool getIsLoggedIn();
    bool signUp(std::string userType);
    bool login(std::string userType);

    ~Auth();

};

#endif