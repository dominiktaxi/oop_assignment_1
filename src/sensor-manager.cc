#include "sensor-manager.h"

SensorManager::SensorManager(MeasurementStorage* storage) : _storage(storage) {}

void SensorManager::addSensor(Sensor::UNIT unit, Sensor::TYPE type, const MinMax &minMax)
{
    _sensors.push_back(std::make_unique<Sensor>(unit, type, minMax));
}

void SensorManager::store(int i)
{
    if( i > _sensors.size() || i < 1)
    {
        std::cerr << "Index out of range" << std::endl;
        return;
    }
    _storage->addMeasurement(_sensors[i - 1]->read());
}

void SensorManager::printAll() const
{
    for ( int i = 0; i < _sensors.size(); i++)
    {
        std::cout << i+1 << "." << _sensors[i]->name() << std::endl;
    }
}

void SensorManager::printAllMeasurements() const
{
    _storage->printAll();
}

void SensorManager::printByType(Sensor::TYPE type) const
{
    _storage->printByType(type);
}

void SensorManager::sortByType()
{
    _storage->sortByType();
}

const std::vector<std::unique_ptr<Sensor>>& SensorManager::sensors() const
{
    return _sensors;
}