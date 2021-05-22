#ifndef LUXURYRIDE_H
#define LUXURYRIDE_H

#include <string>

#include "Driver.h"
#include "PaymentMethod.h"
#include "Ride.h"
#include "Rider.h"

class LuxuryRide : public Ride {
  private:
    bool isWineServed;
    bool isMassageChairOn;
    std::string currentMovie;
    std::string currentSong;

  public:
    LuxuryRide(time_t createdAt, Rider *rider, int price, std::string origin,
               std::string destination, PaymentMethod *paymentMethod);

    virtual void useAmenities() override;

    ~LuxuryRide();
};

#endif