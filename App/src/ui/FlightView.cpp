#include <Precompiled.h>
#include <iostream>
#include <string>
#include <vector>
#include "ui/FlightView.h"
#include "ui/Menu.h"
#include "core/Flight.h"
#include "storage/FlightStorage.h"

void printFlightInfo(Flight& f) {
   std::cout << "Flight " << f.ID << "\n"
   << f.origin << " -> " << f.destination << "\n"
   << "Seats available: " << f.emptySeats << "/" << f.totalSeats << "\n"
   << "Departing at " << f.departureTime << "\n"
   << "Gate " << f.gate << "\t Terminal " << f.terminal << "\n";
   std::cout << "===============================\n";
}

void displayAllFlights() {
   FlightStorage storage;
   Flight f;
   std::vector<std::string> flights = storage.getFlightIDs();

   printTitle();
   for(std::string id : flights) {
      storage.getFlightInfo(id, f);
      printFlightInfo(f);
   }
}