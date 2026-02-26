#pragma once
#include <string>

enum class intErrorCode {InvalidArg = -100, OutOfRange = 100}; // to avoid floating numbers

int parseInt(std::string input);