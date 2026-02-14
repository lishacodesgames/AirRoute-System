#include "ui/BookingView.h"
#include "ui/FlightView.h"
#include "ui/Menu.h"
#include "core/Flight.h"
#include "services/BookingService.h"
#include "utils/ParseUtils.h"
#include "utils/VectorUtils.h"
#include <iostream>

/// @todo TODO fix storage declarations

std::optional<std::string> getCity(std::string type) {
   std::string city;
   int index;
   BookingService booker;
   bool cityValid, tryAgain;

   while(true) {
      printTitle();
      std::cout << "Enter your " + type + " city: ";
      getline(std::cin, city);
   
      cityValid = isValidCity(city, booker);

      if(cityValid)
         return city;
      else {
         tryAgain = promptTryAgain(city + " does not exist.\n");
         if(!tryAgain)
            return std::nullopt;
         else continue;
      }
   }
}

int BookingMenu() {
   std::string input;
   std::pair <bool, int> choice;

   printTitle();
   do {
      std::cout << "===============================\n";
      std::cout << "[0] Go back\n";
      std::cout << "[1] Choose a flight by ID\n";
      std::cout << "[2] Book from Origin city\n";
      std::cout << "===============================\n";
      std::cout << "Enter your choice: ";
      getline(std::cin, input);

      choice = validMenuInput(input, {0, 2});
   } while (!choice.first);

   return choice.second;
}

int OriginChoiceMenu() {
   std::string input;
   std::pair <bool, int> choice;

   printTitle();
   do {
      std::cout << "===============================\n";
      std::cout << "[0] Go back\n";
      std::cout << "[1] Choose a flight by ID\n";
      std::cout << "[2] Book from Destination city\n";
      std::cout << "===============================\n";
      std::cout << "Enter your choice: ";
      getline(std::cin, input);

      choice = validMenuInput(input, {0, 2});
   } while (!choice.first);

   return choice.second;
}

///@param prompt "departing from origin" OR "going from origin -> destination"
int OneFlightMenu(std::string prompt, std::string flightID) {
   std::string input;
   std::pair <bool, int> choice;

   printTitle();
   do {
      std::cout << "There is 1 flight " + prompt << "\n";
      std::cout << "===============================\n";
      std::cout << "[0] Go back\n";
      std::cout << "[1] See flight details\n";
      std::cout << "[2] Book the flight\n";
      std::cout << "===============================\n";
      std::cout << "Enter your choice: ";
      getline(std::cin, input);

      choice = validMenuInput(input, {0, 2});
   } while (!choice.first);

   return choice.second;
}

std::string displayBookingOptions(BookingService& booker) {
   BookingChoice choice = static_cast<BookingChoice>(BookingMenu());

   switch (choice) {
      case BookingChoice::GoBack:
         return "";
      case BookingChoice::byID: {
         return getID(booker.storage.getFlightIDs());
      }
      case BookingChoice::byOrigin: {
         std::string depCity = getCity("origin").value_or(""); // departure city
         if (depCity == "") // user decided to quit
            return "";
         
         std::vector<std::string> originFlights = booker.getValidFlights(depCity);

         switch(originFlights.size()) {
            case 0:
               std::cout << "There are 0 flights departing from " << depCity << "...";
               std::cin.get();
               return "0";
            
            case 1: {
               int menuChoice = OneFlightMenu("departing from " + depCity, originFlights[0]);
               bool toContinue;

               while (true) {
                  switch (menuChoice) {
                     case 0:
                        return displayBookingOptions(booker);
                     
                     case 1: {
                        Flight f;
                        std::string input;

                        printTitle();
                        booker.storage.getFlightInfo(originFlights[0], f);
                        printFlightInfo(f);
                        std::cin.get();
                        while (true) {
                           std::cout << "Would you like to book this flight? (y/n) ";
                           getline(std::cin, input);

                           if (input == "y")
                              return originFlights[0];
                           else if (input == "n")
                              return displayBookingOptions(booker);
                           else {
                              std::cout << "Invalid input.\n";
                           }
                        }
                        break;
                     }

                     case 2:
                        return originFlights[0];
                     }
                  };
                  break;
               }
            default:
               printTitle();
               std::cout << "There are " << originFlights.size() << " flights departing from " << depCity << ".\n";
               break;
         }

         choice = static_cast<BookingChoice>(OriginChoiceMenu());

         switch (choice) {
            case BookingChoice::GoBack: 
               return displayBookingOptions(booker); // loop back

            case BookingChoice::byID: {
               Flight f;

               printTitle();
               return getID(originFlights);
            }
            case BookingChoice::byDestination: {
               std::string arrCity = getCity("destination").value_or(""); // arrival city
               if (arrCity == "") // user decided to quit
                  return "";
               
               std::vector<std::string> destinationFlights = booker.getValidFlights(depCity, arrCity);

               switch(destinationFlights.size()) {
                  case 0:
                     std::cout << "There are 0 flights going from " << depCity << " -> " << arrCity << ".\n";
                     std::cin.get();
                     return "0";
            
                  case 1: {
                     int menuChoice = OneFlightMenu("going from " + depCity + " -> " + arrCity, destinationFlights[0]);
                     bool toContinue;

                     while (true) {
                        switch (menuChoice) {
                           case 0:
                              return displayBookingOptions(booker);
                           
                           case 1: {
                              FlightStorage storage;
                              Flight f;
                              std::string input;

                              printTitle();
                              storage.getFlightInfo(destinationFlights[0], f);
                              printFlightInfo(f);
                              std::cin.get();
                              while (true) {
                                 std::cout << "Would you like to book this flight? (y/n) ";
                                 getline(std::cin, input);

                                 if (input == "y") {
                                    return destinationFlights[0];
                                 }
                                 else if (input == "n") {
                                    return displayBookingOptions(booker);
                                 }
                                 else {
                                    std::cout << "Invalid input.\n";
                                 }
                              }
                              break;
                           }

                           case 2:
                              return originFlights[0];
                        }
                     };
                     break;
                  }
                  default:
                     printTitle();
                     std::cout << "There are " << destinationFlights.size() << " flights going from " << depCity << " -> " << arrCity << ".\n";
                     std::cout << "===============================\n";
                     break;
               }

               printTitle();
               return getID(destinationFlights);
            }
         }

         break;
      }
   }

   return "";
}

/**
 * @brief 1. if ID valid, return it
 * @brief 2. if ID exists but not in validFlights, prompt user "book anyways?"
 * @brief 3. if ID doesn't exist, recursive call to re-prompt ID 
 */
std::string getID(std::vector<std::string> validFlights) {
   BookingService booker;

   if(validFlights.size() == 0) {
      std::cout << "Something went wrong.\n";
      std::cin.get();
      return displayBookingOptions(booker);
   }
   
   // print flights
   FlightStorage storage;
   Flight f;
   
   if(validFlights == storage.getFlightIDs()) 
      displayAllFlights(booker.storage);
   else {
      for (std::string id : validFlights) {
         storage.getFlightInfo(id, f);
         printFlightInfo(f);
      }
   }
   
   std::string ID;
   // flight list ends with "===\n"
   std::cout << "===============================\n";
   std::cout << "Enter flight ID: ";
   getline(std::cin, ID);

   int validIndex = getIndex(ID, validFlights);
   if (validIndex != -1) // valid ID
      return ID;

   std::string temp;
   std::vector<std::string> allFlights = storage.getFlightIDs();
   if(validFlights != allFlights) {
      int flightIndex = getIndex(ID, allFlights);

      if(flightIndex != -1) { // ID doesn't match criteria but it exists
         std::cout << "\nFlight " << ID << " does not match the selected criteria.\n";
         std::cout << "Would you like to book flight " << ID << " anyways? (y/n) ";
         getline(std::cin, temp);
         if (temp == "y")
            return ID;
         else if (temp == "n")
            return displayBookingOptions(booker);
         else {
            printTitle();
            std::cout << "Invalid input.\n";
            return getID(validFlights);
         }
      }
   }

   // flight doesn't exist
   bool tryAgain = promptTryAgain("\nFlight " + ID + " does not exist.");

   if(tryAgain) {
      printTitle();
      return getID(validFlights);
   }
   else
   return displayBookingOptions(booker);
}