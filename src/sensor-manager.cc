#include "sensor-manager.h"

SensorManager::SensorManager() {}

void SensorManager::addSensor(Sensor::UNIT unit, Sensor::TYPE type, const std::string &name, const MinMax &minMax)
{
    _sensors.push_back(std::make_unique<Sensor>(unit, type, name, minMax));
}

void SensorManager::readAndStore(Sensor::TYPE type)
{
    for(const auto& sensor : _sensors)
    {
        if (sensor->type() == type)
        {
            _storage.addMeasurement(sensor->read());
        }
    }
}