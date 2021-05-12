#ifndef CASH_H
#define CASH_H

#include <string>

#include "PaymentMethod.h"

class Cash : public PaymentMethod
{
private:

public:
    Cash();

    virtual bool pay(int amount);

    ~Cash();

};

#endif