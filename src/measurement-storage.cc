#include "measurement-storage.h"

MeasurementStorage::MeasurementStorage() {}

void MeasurementStorage::addMeasurement(std::unique_ptr<Measurement> measurement)
{
    _measurements.push_back(std::move(measurement));
}

void MeasurementStorage::printAll() const
{
    for (const auto &measurement : _measurements)
    {
        std::cout << "Name: " << measurement->name << std::endl;
        std::cout << "Type: " << measurement->type << std::endl;
        std::cout << "Date: " << measurement->timeStamp << std::endl;
        std::cout << "Measurement: " << measurement->measurement << " " << measurement->unit << std::endl << std::endl;
    }
}