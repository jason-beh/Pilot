#ifndef AUTH_H
#define AUTH_H

#include <string>

class Auth {
    private: 
        Auth(std::string newUserEmail, std::string newUserPassword);
        
        std::string email;
        std::string password;

        void changePassword(std::string newPassword, std::string oldPassword);

        ~Auth();
};

#endif