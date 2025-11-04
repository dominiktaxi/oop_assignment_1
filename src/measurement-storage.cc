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

void MeasurementStorage::statistics(const std::string& type) const
{
    float average = 0.f;
    int amountOfReadings = 0;
    MinMax minMax;
    for(const auto& measurement : _measurements)
    {
        if (measurement->type == type )
        {
            average = ::average(_measurements, type);
            amountOfReadings++;
        }
        minMax = ::minMax(_measurements, type);
    }
    std::cout << "Average: " << average << std::endl;
    std::cout << "Amount of readings: " << amountOfReadings << std::endl;
    std::cout << "Min value: " << minMax.min << "| Max value: " << minMax.max << std::endl;
}