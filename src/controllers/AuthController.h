#ifndef AUTHCONTROLLER_H
#define AUTHCONTROLLER_H

#include "../classes/User.h"
#include <string>

void AuthController();

bool AuthIsRiderOrDriver();
bool AuthIsUserWantsToLogin();


#endif