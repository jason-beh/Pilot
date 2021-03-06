#ifndef ACCOUNTBALANCE_H
#define ACCOUNTBALANCE_H

#include <string>

#include "PaymentMethod.h"

class AccountBalance : public PaymentMethod {
  public:
    AccountBalance();

    virtual bool pay(int amount);

    ~AccountBalance();
};

#endif