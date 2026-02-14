#pragma once
#include <string>
#include <vector>
#include <optional>

enum class BookingChoice {GoBack, byID, byOrigin, byDestination};

/// @param type "origin" OR "destination" gets printed in the prompt
/// @retval std::nullopt IF user decided to quit
std::optional<std::string> getCity(std::string type);

int BookingMenu();
int OriginChoiceMenu();
int OneFlightMenu(std::string prompt, std::string flightID);
std::string displayBookingOptions(FlightStorage& storage);
std::string getID(std::vector<std::string> validFlights);