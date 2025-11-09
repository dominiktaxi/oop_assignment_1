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
    void saveAlltoHDD();
    void loadFromHDD();
    void printAll() const;
    void printByType(Sensor::TYPE) const;
    void statistics(const std::string& type) const;
    void sortByType();

private:
    std::vector<std::unique_ptr<Measurement>> _measurements;
};