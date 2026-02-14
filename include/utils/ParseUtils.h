#pragma once
#include <string>
#include <optional>

enum class intErrorCode {NoError = 0, InvalidArg = -100, OutOfRange = 100}; // to avoid floating numbers

std::pair< std::optional<int>, intErrorCode > parseInt(std::string input);