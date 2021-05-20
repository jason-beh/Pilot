#ifndef LUXURYRIDE_H
#define LUXURYRIDE_H

#include <string>

#include "Driver.h"
#include "PaymentMethod.h"
#include "Rider.h"
#include "Ride.h"

class LuxuryRide: public Ride {
   private:
     int remainingWineServings;
     bool isMassageChairOn;
     std::string currentMovie;
     std::string currentSong;

   public:
        using Ride::Ride;

        virtual void useAmenities() override;

        ~LuxuryRide();
};

#endif