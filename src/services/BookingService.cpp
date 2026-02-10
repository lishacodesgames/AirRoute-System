#include "services/BookingService.h"
#include "core/Flight.h"
#include "storage/FlightStorage.h"
#include "ui/BookingView.h"
#include <string>
#include <vector>

#include <iostream> //REMOVE REMOVE TODO TODO ATTENTIONS
void BookingService::bookFlight() {
   std::string ID = displayBookingOptions();
   if(ID == "" || ID == "0")
      std::cout << "FLIGHT WAS NOT BOOKED.";
   else 
      std::cout << "FLIGHT BOOKED: " << ID;
}

/**
 * @param validator "origin" OR "destination"
 * @param targetCity depCity (departure, origin) OR arrCity (arrival, destination)
 * @return vector of flight IDs containing targetCity as validator
 */
std::vector<std::string> BookingService::getValidFlights(std::string validator, std::string targetCity) {
   FlightStorage storage;
   Flight f;
   std::vector<std::string> allFlights = storage.getFlightIDs();

   std::vector<std::string> originFlights = {};
   for (std::string id : allFlights) {
      storage.getFlightInfo(id, f);
      if (f.origin == targetCity)
         originFlights.push_back(id);
   }
   
   if (validator == "origin")
      return originFlights;
   else if (validator == "destination") {
      std::vector<std::string> destinationFlights = {};
      for (std::string id : originFlights) {
         storage.getFlightInfo(id, f);
         if (f.destination == targetCity)
            destinationFlights.push_back(id);
      }
      return destinationFlights;
   }
    
   return {}; // invalid validator
}

