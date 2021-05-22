#ifndef CREDITCARD_H
#define CREDITCARD_H

#include <string>

#include "PaymentMethod.h"

class CreditCard : public PaymentMethod {
  private:
  public:
    CreditCard();

    virtual bool pay(int amount);

    ~CreditCard();
};

#endif