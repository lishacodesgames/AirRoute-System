#include "utils/ParseUtils.h"
#include <iostream> // ik it's bad.
#include <stdexcept>

/// @brief returns -100 if not number, 100 if out of range
int parseInt(std::string input) {
   int output;

   try {
      output = std::stoi(input);
   } catch(std::invalid_argument& e) {
      std::cout << "\nInvalid input.\n";
      return static_cast<int>(intErrorCode::InvalidArg);
   } catch(std::out_of_range& e) {
      std::cout << "\nWhy would you do that?\n";
      return static_cast<int>(intErrorCode::OutOfRange);
   }

   return output;
}