#include "utils.h"

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