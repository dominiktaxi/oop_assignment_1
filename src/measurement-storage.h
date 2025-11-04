#pragma once
#include "measurement.h"
#include "sensor.h"
#include <vector>
#include <memory>

class MeasurementStorage
{
public:
    MeasurementStorage();
    void addMeasurement(std::unique_ptr<Measurement>);
    void printAll() const;

private:
    std::vector<std::unique_ptr<Measurement>> _measurements;
};