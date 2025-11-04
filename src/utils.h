#pragma once
#include <chrono>
#include <ctime>
#include <random>
struct MinMax
{
    float min;
    float max;
};

float randomFloat(float min, float max);

std::string localTime();