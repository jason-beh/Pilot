#include "Rider.h"
#include "User.h"
#include "Auth.h"

#include <string>

using namespace std;

int Rider::globalRiderId = 1;

Rider::Rider() {
    riderId = globalRiderId++;

    int currentBalance = 0;
    authDetails = new Auth();
}

int Rider::getCurrentBalance() {
    return currentBalance;
}

bool Rider::topUp(int amount) {
    return false;
};

Rider::~Rider() {}