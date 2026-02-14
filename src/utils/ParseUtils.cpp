#include "utils/ParseUtils.h"
#include <stdexcept>
#include <iostream>
#include <utility>

/**
 * @retval -100 if input not a number
 * @retval  100 if input number out of range
 */
std::pair<std::optional<int>, intErrorCode> parseInt(std::string input) {
   int output;

   try {
      output = std::stoi(input);
   } catch(const std::invalid_argument& e) {
      return {std::nullopt, intErrorCode::InvalidArg};
   } catch(const std::out_of_range& e) {
      return {std::nullopt, intErrorCode::OutOfRange};
   }

   return {output, intErrorCode::NoError};
}