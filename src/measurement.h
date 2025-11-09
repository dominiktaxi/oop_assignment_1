#pragma once
#include <string>
#include <vector>
#include "sensor.h"
struct Measurement
{
    std::string timeStamp;
    std::string unit;
    std::string type;
    Sensor::TYPE TYPE;
    float reading;
};