#include <memory>
#include <cmath>
#include "sensor.h"
#include "measurement.h"

Sensor::Sensor(UNIT unit, TYPE type, const MinMax &minMax) :  _UNIT(unit), _TYPE(type),
                                                              _minMax(minMax)
{
    switch (type)
    {
    case Sensor::TYPE::HUMIDITY: { _type = "humidity"; } break;
    case Sensor::TYPE::TEMPERATURE:{_type = "temperature"; } break;
    }

    switch (unit)
    {
    case Sensor::UNIT::CELSIUS: { _unit = "celsius"; } break;
    case Sensor::UNIT::PERCENTAGE: { _unit = "%"; } break;
    }
}

std::unique_ptr<Measurement> Sensor::read() const
{
    float reading = randomFloat(_minMax.min, _minMax.max);
    reading = std::round(reading * 100) / 100; //round to 2 decimals
    auto measurement = std::make_unique<Measurement>();
    measurement->TYPE = _TYPE;
    measurement->type = _type;
    measurement->unit = _unit;
    measurement->reading = reading;
    measurement->timeStamp = ::localTime();
    return measurement;
}

Sensor::TYPE Sensor::type() const
{
    return _TYPE;
}

const std::string& Sensor::name() const
{
    return _type;
}