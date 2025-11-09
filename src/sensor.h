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
        PERCENTAGE
    };
    enum class TYPE
    {
        HUMIDITY,
        TEMPERATURE,
    };
    Sensor(UNIT, TYPE, const MinMax &);
    std::unique_ptr<Measurement> read() const;
    TYPE type() const;
    const std::string& name() const;

private:
    std::string _type;
    std::string _unit;
    const UNIT _UNIT;
    const TYPE _TYPE;
    const MinMax _minMax;
};