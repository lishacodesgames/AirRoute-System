#pragma once
#include "core/Flight.h"
#include "storage/FlightStorage.h"
#include <vector>
#include <string>

class FlightGenerator {
public:
   Flight generateRandom();
};