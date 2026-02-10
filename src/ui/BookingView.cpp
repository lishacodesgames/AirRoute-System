#include "ui/BookingView.h"
#include "ui/Menu.h"
#include "storage/FlightStorage.h"
#include "utils/VectorUtils.h"
#include <iostream>
#include <string>

std::string getCity(std::string type) {
   std::string city;
   int index;
   FlightStorage storage;
   bool repeat = false;

   printTitle();
   std::cout << "Enter your " + type + " city";
   getline(std::cin, city);

   index = getIndex(city, storage.getCities());

   if(index == -1) {
      repeat = promptTryAgain();
      return repeat ? getCity(type) : "";
   }
   else 
      return city;
}

int BookingMenu() {
   printTitle();
   
}