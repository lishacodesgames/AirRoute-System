#include "utils/ParseUtils.h"
#include <iostream> // ik it's bad.
#include <string>
#include <stdexcept>

/// @brief returns -100 if error
int parseInt(std::string input) {
   int output;

   try {
      output = std::stoi(input);
   } catch(std::invalid_argument& e) {
      std::cout << "\nInvalid input.\n";
      return -100;
   } catch(std::out_of_range& e) {
      std::cout << "\nWhy would you do that?\n";
      return -100;
   }

   return output;
}