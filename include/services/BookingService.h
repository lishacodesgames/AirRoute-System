#pragma once
#include "storage/FlightStorage.h"
#include <string>
#include <vector>

class BookingService {
   static FlightStorage& storage;
   friend bool isValidCity(std::string city, BookingService& booker);
public:
   BookingService(){}
   BookingService(FlightStorage& storage) {
      this->storage = storage;
   }
   void bookFlight();

   /// @return originFlights
   std::vector<std::string> getValidFlights(std::string depCity);
   
   /// @return destinationFlights
   std::vector<std::string> getValidFlights(std::string depCity, std::string arrCity);
};