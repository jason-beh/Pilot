#ifndef RIDE_H
#define RIDE_H

#include <string>

#include "Driver.h"
#include "PaymentMethod.h"
#include "Rider.h"

class Ride {
  private:
    Rider *rider;
    PaymentMethod *paymentMethod;
    int price;
    std::string origin;
    std::string destination;
    time_t createdAt;

    bool isRadioOn;

  public:
    Ride(time_t createdAt, Rider *rider, int price, std::string origin,
         std::string destination, PaymentMethod *paymentMethod);

    virtual void useAmenities();

    ~Ride();
};

#endif