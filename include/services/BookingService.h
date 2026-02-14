#pragma once
#include "storage/FlightStorage.h"
#include <string>
#include <vector>

class BookingService {
   public:
   static FlightStorage storage;
   
   BookingService(); //empty
   BookingService(FlightStorage& storage);
   
   void bookFlight();
   
   /// @return originFlights
   std::vector<std::string> getValidFlights(std::string depCity);
   
   /// @return destinationFlights
   std::vector<std::string> getValidFlights(std::string depCity, std::string arrCity);
};

bool isValidCity(std::string city, BookingService& booker);