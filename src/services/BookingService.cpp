#include "services/BookingService.h"
#include "core/Flight.h"
#include "ui/BookingView.h"
#include "utils/VectorUtils.h"

BookingService::BookingService(){}
BookingService::BookingService(FlightStorage& storage) {
   this->storage = storage;
}

/// @todo TODO REMOVE!
#include <iostream>
void BookingService::bookFlight() {
   std::string ID = displayBookingOptions(booker);
   if (ID == "" || ID == "0")
      std::cout << "FLIGHT WAS NOT BOOKED.";
   else 
      std::cout << "FLIGHT BOOKED: " << ID;
}

std::vector<std::string> BookingService::getValidFlights(std::string depCity) {
   Flight f;
   std::vector<std::string> allFlights = storage.getFlightIDs();

   std::vector<std::string> originFlights = {};
   for (std::string id : allFlights) {
      storage.getFlightInfo(id, f);
      if (f.origin == depCity)
         originFlights.push_back(id);
   }

   return originFlights;
}

std::vector<std::string> BookingService::getValidFlights(std::string depCity, std::string arrCity) {
   Flight f;
   std::vector<std::string> allFlights = storage.getFlightIDs();
   std::vector<std::string> originFlights = getValidFlights(depCity);

   std::vector<std::string> destinationFlights = {};
   for (std::string id : originFlights) {
      storage.getFlightInfo(id, f);
      if (f.destination == arrCity)
         destinationFlights.push_back(id);
   }

   return destinationFlights;
}

bool isValidCity(std::string city, BookingService& booker) {
   int index = getIndex(city, booker.storage.getCities());

   return index == -1 ? false : true;
}