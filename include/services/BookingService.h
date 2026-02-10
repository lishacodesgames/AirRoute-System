#pragma once
#include <string>
#include <vector>

class BookingService {
public:
   void bookFlight();
   std::vector<std::string> getValidFlights(std::string validator, std::string targetCity);
};