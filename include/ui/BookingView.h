#pragma once
#include <string>
#include <vector>

enum class BookingChoice {GoBack, byID, byOrigin, byDestination};

std::string getCity(std::string type);
int BookingMenu();
int OriginChoiceMenu();
int OneFlightMenu(std::string prompt, std::string flightID);
std::string displayBookingOptions(FlightStorage& storage);
std::string getID(std::vector<std::string> validFlights);