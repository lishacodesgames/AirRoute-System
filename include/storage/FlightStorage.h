#pragma once
#include "core/Flight.h"
#include <vector>
#include <string>
#include <fstream>

class FlightStorage {
public:
   std::vector<std::string> getFlightIDs();
   std::vector<std::string> getCities();
   void saveFlight(Flight& flight);
   bool getFlightInfo(const std::string& ID, Flight& outputFlight);
};