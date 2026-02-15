#include "services/BookingService.h"
#include "storage/FlightStorage.h"
#include "ui/BookingView.h"
#include "utils/VectorUtils.h"
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

/// @return originFlights
std::vector<std::string> BookingService::getValidFlights(std::string depCity) {
   Flight f;
   std::vector<std::string> allFlights = storage.getFlightIDs();

   std::vector<std::string> originFlights = {};
   for (std::string id : allFlights) {
      f = storage.getFlightInfo(id).value();
      if (f.origin == depCity)
         originFlights.push_back(id);
   }

   return originFlights;
}

/// @return destinationFlights
std::vector<std::string> BookingService::getValidFlights(std::string depCity, std::string arrCity) {
   Flight f;
   std::vector<std::string> allFlights = storage.getFlightIDs();
   std::vector<std::string> originFlights = getValidFlights(depCity);

   std::vector<std::string> destinationFlights = {};
   for (std::string id : originFlights) {
      f = storage.getFlightInfo(id).value();
      if (f.destination == arrCity)
         destinationFlights.push_back(id);
   }

   return destinationFlights;
}

std::vector<std::string> BookingService::getAllFlights() {
   return storage.getFlightIDs();
}

std::optional<Flight> BookingService::getFlight(std::string ID) {
   return storage.getFlightInfo(ID);
}

bool isValidCity(std::string city, BookingService& booker) {
   int index = getIndex(city, booker.storage.getCities());

   return index == -1 ? false : true;
}