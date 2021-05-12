#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle
{
private:
    std::string vehiclePlateNumber;
    static int globalVehicleId;

    int vehicleId;
    bool isRadioPlaying;

public:
    Vehicle();

    void listenToRadio();
    void setRadio(bool mode);

    ~Vehicle();

};

#endif