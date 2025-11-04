#pragma once
#include <vector>
#include <memory>
#include "sensor.h"
#include "measurement-storage.h"

class SensorManager
{
    public:
    SensorManager();
    void addSensor(Sensor::UNIT, Sensor::TYPE, const std::string &, const MinMax &);
    void readAndStore(Sensor::TYPE);
    private:
    std::vector<std::unique_ptr<Sensor>> _sensors;
    MeasurementStorage _storage;
};
