#pragma once
#include <vector>
#include <memory>
#include "sensor.h"
#include "measurement-storage.h"

class SensorManager
{
    public:
    SensorManager(MeasurementStorage* storage);
    void addSensor(Sensor::UNIT, Sensor::TYPE, const MinMax &);
    void store(int i);
    void printAll() const;
    void printAllMeasurements() const;
    void printByType(Sensor::TYPE) const;
    void sortByType();
    const std::vector<std::unique_ptr<Sensor>>& sensors() const;
    private:
    std::vector<std::unique_ptr<Sensor>> _sensors;
    MeasurementStorage* _storage;
};
