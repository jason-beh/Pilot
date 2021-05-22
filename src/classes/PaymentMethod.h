#ifndef PAYMENTMETHOD_H
#define PAYMENTMETHOD_H

#include <string>

#include "Driver.h"
#include "Rider.h"

class PaymentMethod
{
private:

public:
    PaymentMethod();

    virtual bool pay(int amount)=0;

    virtual ~PaymentMethod();

};

#endif