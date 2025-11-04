#pragma once
#include "sensor.h"
#include <vector>
struct Measurement
{
    std::string name;
    std::string timeStamp;
    std::string unit;
    std::string type;
    float measurement;
};