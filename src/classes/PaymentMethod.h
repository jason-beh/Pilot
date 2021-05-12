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

    virtual void pay()=0;

    ~PaymentMethod();

};

#endif