#include <memory>
#include "sensor.h"
#include "measurement.h"

Sensor::Sensor(UNIT unit, TYPE type, const std::string &name, const MinMax &minMax) : _name(name), _Unit(unit), _Type(type),
                                                                                      _minMax(minMax)
{
    switch (type)
    {
    case Sensor::TYPE::HUMIDITY: { _type = "humidity"; } break;
    case Sensor::TYPE::SPEED: { _type = "speed"; } break;
    case Sensor::TYPE::TEMPERATURE:{_type = "temperature"; } break;
    }

    switch (unit)
    {
    case Sensor::UNIT::CELSIUS: { _unit = "celsius"; } break;
    case Sensor::UNIT::FAHRENHEIT: { _unit = "fahrenheit"; } break;
    case Sensor::UNIT::KELVIN: { _unit = "kelvin"; } break;
    case Sensor::UNIT::PERCENTAGE: { _unit = "%"; } break;
    }
}

std::unique_ptr<Measurement> Sensor::read() const
{
    float reading = randomFloat(_minMax.min, _minMax.max);
    auto measurement = std::make_unique<Measurement>();
    measurement->type = _type;
    measurement->unit = _unit;
    measurement->measurement = reading;
    measurement->name = _name;
    measurement->timeStamp = ::localTime();
    return measurement;
}

Sensor::TYPE Sensor::type() const
{
    return _Type;
}