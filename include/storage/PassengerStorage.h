#pragma once
#include "core/Passenger.h"
#include "storage/FlightStorage.h"
#include <string>
#include <filesystem>

class PassengerStorage {
   static std::filesystem::path passengers;
public:
   PassengerStorage();
   PassengerStorage(const std::filesystem::path& BASE);
   bool getPassengerInfo(std::string name, Passenger& outputP);
};