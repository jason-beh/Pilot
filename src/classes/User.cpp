#include "User.h"
#include "Auth.h"

#include <string>

using namespace std;

int User::globalUserId = 1;

User::User() {
    user_id = globalUserId++;

    authDetails = new Auth();
}

User::~User() {}