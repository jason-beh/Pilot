#include "LuxuryRide.h"

#include <string>
#include <iostream>

#include "Ride.h"
#include "../utils/generateUserOptions.h"

using namespace std;

void LuxuryRide::useAmenities() {
    std::cout << "Welcome to your ride! You can now do the following: " << std::endl;

    std::cout << "1. Drink wine" << std::endl;
    if(isMassageChairOn == true) {
        std::cout << "2. Turn off massage chair" << std::endl;
    } else {
        std::cout << "2. Turn on massage chair" << std::endl;
    }
    std::cout << "3. Choose movie" << std::endl;
    std::cout << "4. Choose song" << std::endl;
    std::cout << "5. Complete ride" << std::endl;

    int option = generateUserOptions(5);

    switch (option) {
        case 1: {
            if(remainingWineServings != 0) {
                std::cout << "Served wine!" << std::endl;
                remainingWineServings--;
            } else {
                std::cout << "Wine has run out" << std::endl;
            }
            break;
        }
        case 2: {
            if(isMassageChairOn == true) {
                std::cout << "Massage chair is now turned on" << std::endl;
            } else {
                std::cout << "Massage chair is now turned off" << std::endl;
            }
            break;
        }
        case 3: {
            std::string songChosen;
            std::cout << "Please enter a song you would like to play:" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, songChosen);
            currentSong = songChosen;
            std::cout << "Playing " << songChosen << std::endl;
            break;
        }
        case 4: {
            std::string movieChosen;
            std::cout << "Please enter a movie you would like to watch:" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, movieChosen);
            currentMovie = movieChosen;
            std::cout << "Playing " << movieChosen << std::endl;
            break;
        }
    }
};

LuxuryRide::~LuxuryRide() {}