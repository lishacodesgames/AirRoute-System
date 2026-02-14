#pragma once
#include "services/BookingService.h"
#include <string>
#include <vector>
#include <optional>

enum class BookingChoice {GoBack, byID, byOrigin, byDestination};

/// @param type "origin" OR "destination" gets printed in the prompt
/// @retval std::nullopt IF user decided to quit
std::optional<std::string> getCity(std::string type);

int BookingMenu();
int OriginChoiceMenu();

///@param prompt "departing from origin" OR "going from origin -> destination"
int OneFlightMenu(std::string prompt, std::string flightID);

std::string displayBookingOptions(BookingService& booker);

/// @brief 1. if ID valid, return it
/// @brief 2. if ID exists but not in validFlights, prompt user "book anyways?"
/// @brief 3. if ID doesn't exist, recursive call to re-prompt ID 
std::string getID(std::vector<std::string> validFlights);