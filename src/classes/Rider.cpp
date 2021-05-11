#include "Rider.h"
#include "User.h"
#include "Auth.h"

#include <string>

using namespace std;

int Rider::globalRiderId = 1;

Rider::Rider() {
    rider_id = globalRiderId++;

    int currentBalance = 0;
    authDetails = new Auth();
}

bool Rider::topUp(int amount) {
    return false;
};

Rider::~Rider() {}