#pragma once
#include <iostream>
#include "utils.h"
class Measurement;
class Sensor
{
public:
    enum class UNIT
    {
        CELSIUS,
        FAHRENHEIT,
        KELVIN,
        PERCENTAGE
    };
    enum class TYPE
    {
        HUMIDITY,
        TEMPERATURE,
        SPEED
    };
    Sensor(UNIT, TYPE, const std::string &, const MinMax &);
    std::unique_ptr<Measurement> read() const;
    TYPE type() const;

private:
    std::string _name;
    std::string _type;
    std::string _unit;
    const UNIT _Unit;
    const TYPE _Type;
    const MinMax _minMax;
};