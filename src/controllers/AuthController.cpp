#include "AuthController.h"
#include "../classes/User.h"
#include "../classes/Driver.h"

#include <fstream>
#include <iostream>
#include <string>

std::string AuthController()
{
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Welcome to Pilot!" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "To begin using Pilot, are you a driver or rider? (Please select your options based on the number)" << std::endl << std::endl;

    std::cout << "1. Rider" << std::endl;
    std::cout << "2. Driver" << std::endl << std::endl;

    int optionChosen;

    std::cout << "Enter decision: ";
    std::cin >> optionChosen; 

    if(optionChosen == 1) {
        return "Rider";
    } 
    
    return "Driver";
}