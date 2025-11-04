#pragma once
#include <chrono>
#include <ctime>
#include <random>
#include <memory>
#include "measurement.h"
struct MinMax
{
    float min;
    float max;
};

float randomFloat(float min, float max);

std::string localTime();

float average(const std::vector<std::unique_ptr<Measurement>>&, const std::string& type);

MinMax minMax(const std::vector<std::unique_ptr<Measurement>>& measurements, const std::string& type);