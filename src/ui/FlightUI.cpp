#include "ui/FlightUI.h"
#include "ui/MenuUI.h"
#include "core/Flight.h"
#include "storage/FlightStorage.h"
#include <vector>
#include <string>
#include <iostream>
#include <optional>

void printFlightInfo(Flight& flight) {
   std::cout << "Flight " << flight.ID << "\n"
   << flight.origin << " -> " << flight.destination << "\n"
   << "Seats available: " << flight.emptySeats << "/" << flight.totalSeats << "\n"
   << "Departing at " << flight.departureTime << "\n"
   << "Gate " << flight.gate << "\t Terminal " << flight.terminal << "\n";
   std::cout << "===============================\n";
}

bool displayFlight(std::string ID) {
   FlightStorage storage;
   std::vector<std::string> allFlights = storage.getFlightIDs();
   bool flightExists = false;
   
   std::optional<Flight> flight = storage.getFlightInfo(ID);

   if(flight) {
      printTitle();
      printFlightInfo(flight.value());
      std::cin.get();
      return true;
   }

   return false;
}

void displayAllFlights() {
   FlightStorage storage;
   Flight f;
   std::vector<std::string> flights = storage.getFlightIDs();

   printTitle();
   for(std::string id : flights) {
      f = storage.getFlightInfo(id).value();
      printFlightInfo(f);
   }
}