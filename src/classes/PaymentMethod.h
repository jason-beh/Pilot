#ifndef PAYMENTMETHOD_H
#define PAYMENTMETHOD_H

#include <string>

class PaymentMethod {
  public:
    PaymentMethod();

    virtual bool pay(int amount) = 0;

    virtual ~PaymentMethod();
};

#endif