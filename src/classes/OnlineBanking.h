#ifndef ONLINEBANKING_H
#define ONLINEBANKING_H

#include <string>

#include "PaymentMethod.h"

class OnlineBanking : public PaymentMethod {
  private:
  public:
    OnlineBanking();

    virtual bool pay(int amount);

    ~OnlineBanking();
};

#endif