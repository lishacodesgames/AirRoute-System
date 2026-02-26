#pragma once
#include "core/Passenger.h"
#include <string>
#include <fstream>

class PassengerStorage {
public:
   bool getPassengerInfo(std::string name, Passenger& outputP);
};