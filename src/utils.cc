#include "utils.h"
#include "measurement.h"

float randomFloat(float min, float max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(min, max);
    return dist(gen);
}

std::string localTime()
{
    auto now = std::chrono::system_clock::now();
    std::time_t time_now = std::chrono::system_clock::to_time_t(now);
    std::string timeStr = std::ctime(&time_now);
    if(timeStr.back() == '\n')
    {
        timeStr.pop_back();
    }
    return timeStr;
}

float average(const std::vector<std::unique_ptr<Measurement>>& measurements, const std::string& type)
{
    float total = 0.f;
    int amount = 0;
    float average = 0.f;
    for(const auto& measurement : measurements)
    {
        if(measurement->type == type)
        {
            total += measurement->reading;
            amount++;
        }
    }
    average = total / static_cast<float>(amount);
    float roundedAverage = std::round(average * 100) / 100;
    return roundedAverage;
}

MinMax minMax(const std::vector<std::unique_ptr<Measurement>>& measurements, const std::string& type)
{
    bool first_hit = false;
    MinMax minMax;
    float min = 0.f;
    float max = 0.f;
    for(const auto& measurement : measurements)
    {
        if(measurement->type == type)
        {
            if(!first_hit) {min = measurement->reading;}
            if(max < measurement->reading)
            {
                max = measurement->reading;
            }
            if(min > measurement->reading)
            {
                min = measurement->reading;
            }
            first_hit = true;
        }
    }
    return MinMax{min, max};
}