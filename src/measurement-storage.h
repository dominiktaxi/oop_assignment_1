#pragma once
#include "measurement.h"
#include "sensor.h"
#include "utils.h"
#include <vector>
#include <memory>

class MeasurementStorage
{
public:
    MeasurementStorage();
    void addMeasurement(std::unique_ptr<Measurement>);
    void printAll() const;
    void statistics(const std::string& type) const;

private:
    std::vector<std::unique_ptr<Measurement>> _measurements;
};