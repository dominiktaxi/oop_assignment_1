#include "measurement-storage.h"
#include <algorithm>
#include <fstream>
#include <sstream>



MeasurementStorage::MeasurementStorage() {}

void MeasurementStorage::addMeasurement(std::unique_ptr<Measurement> measurement)
{
    _measurements.push_back(std::move(measurement));
}

void MeasurementStorage::saveAlltoHDD()
{
    if(_measurements.size() > 0)
    {
        std::ofstream humidityReadings ("measurements/humidityReadings.txt", std::ios::app);
        std::ofstream temperatureReadings ("measurements/temperatureReadings.txt", std::ios::app);
        if(!humidityReadings || !temperatureReadings)
        {
            std::cerr << "Failed to create file" << std::endl;
            return;
        }
        for (const auto& measurement : _measurements)
        {
            if ( measurement->TYPE == Sensor::TYPE::HUMIDITY)
            {
                humidityReadings << measurement->reading << "," << measurement->unit << "," << measurement->timeStamp << "," 
                << static_cast<int>(measurement->TYPE) << "," << measurement->type << "\n";
            }
            else if(measurement->TYPE == Sensor::TYPE::TEMPERATURE)
            {
                temperatureReadings << measurement->reading << "," << measurement->unit << "," << measurement->timeStamp << "," 
                << static_cast<int>(measurement->TYPE) << "," << measurement->type << "\n";
            }
        }
        temperatureReadings.close();
        humidityReadings.close();
    }
    else {std::cout << "No data was saved" << std::endl;}
}

void MeasurementStorage::loadFromHDD()
{
    std::string line;
    std::ifstream temperatureReadings("measurements/temperatureReadings.txt");
    std::ifstream humidityReadings("measurements/humidityReadings.txt");
    while (getline(temperatureReadings, line, '\n' ))
    {
        std::stringstream ss (line);
        std::string reading, unit, timeStamp, TYPE, type;
        getline(ss, reading, ',');
        getline(ss, unit, ',');
        getline(ss, timeStamp, ',');
        getline(ss, TYPE, ',');
        getline(ss, type, ',');
        std::unique_ptr<Measurement> measurement = std::make_unique<Measurement>();
        measurement->reading = std::stof(reading);
        measurement->unit = unit;
        measurement->timeStamp = timeStamp;
        measurement->TYPE = static_cast<Sensor::TYPE>(std::stoi(TYPE));
        measurement->type = type;
        _measurements.push_back(std::move(measurement));
    }
    while (getline(humidityReadings, line, '\n' ))
    {
        std::stringstream ss (line);
        std::string reading, unit, timeStamp, TYPE, type;
        getline(ss, reading, ',');
        getline(ss, unit, ',');
        getline(ss, timeStamp, ',');
        getline(ss, TYPE, ',');
        getline(ss, type, ',');
        std::unique_ptr<Measurement> measurement = std::make_unique<Measurement>();
        measurement->reading = std::stof(reading);
        measurement->unit = unit;
        measurement->timeStamp = timeStamp;
        measurement->TYPE = static_cast<Sensor::TYPE>(std::stoi(TYPE));
        measurement->type = type;
        _measurements.push_back(std::move(measurement));
    }
}

void MeasurementStorage::eraseData()
{
    if(!std::remove("measurements/temperatureReadings.txt"))
    {
        std::cout << "Temperature readings file erased" << std::endl;
    }
    else {std::cout << "No temperature readings stored" << std::endl;}

    if(!std::remove("measurements/humidityReadings.txt"))
    {
        std::cout << "Humidity readings file erased" << std::endl;
    }
    else {std::cout << "No humidity readings stored" << std::endl;}
    if(_measurements.size() > 0)
    {
    _measurements.clear();
    }
    else {std::cout << "Nothing to clear in memory" << std::endl;}
}

float MeasurementStorage::average(Sensor::TYPE TYPE) const
{
    std::string type;
    if(TYPE == Sensor::TYPE::HUMIDITY) type = "humidity";
    if(TYPE == Sensor::TYPE::TEMPERATURE) type = "temperature";
    return ::average(_measurements, type);
}

void MeasurementStorage::printAll() const
{
    std::string type;
    for (const auto &measurement : _measurements)
    {
        if(measurement->TYPE == Sensor::TYPE::HUMIDITY) type = "Humidity sensor";
        else if(measurement->TYPE == Sensor::TYPE::TEMPERATURE) type = "Temperature sensor";
        std::cout << "Type: " << type << std::endl;
        std::cout << "Date: " << measurement->timeStamp << std::endl;
        std::cout << "Measurement: " << measurement->reading << " " << measurement->unit << std::endl << std::endl;
    }
}

void MeasurementStorage::printByType(Sensor::TYPE type) const
{
    for ( const auto& measurement : _measurements)
    {
        if ( measurement->TYPE == type)
        {

        }
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

void MeasurementStorage::sortByType()
{
std::sort(_measurements.begin(), _measurements.end(), [] (const std::unique_ptr<Measurement>& a, 
                                                                    const std::unique_ptr<Measurement>& b)
                                                                   {return a->TYPE < b->TYPE;} );
}