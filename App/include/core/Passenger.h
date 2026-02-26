#pragma once
#include <string>

struct Passenger {
   std::string name;
   int age; // ∈ [1, 99]
   std::string seat; // 2-digit number <= totalSeats/5 + CHAR(A-E)
   std::string bookedFlight;
};