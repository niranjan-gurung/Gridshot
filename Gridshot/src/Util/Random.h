#pragma once

#include <random>

// alias
using RandomNumber = std::uniform_int_distribution<uint32_t>;

class Random
{
public:
    Random();
    uint32_t DrawNumber(uint32_t min, uint32_t max);

private:        
    std::random_device dev;
    std::mt19937 rng;
};

inline Random::Random()
    : rng(dev()) {}

inline uint32_t Random::DrawNumber(uint32_t min, uint32_t max) 
{ 
    return RandomNumber{min, max}(rng); 
}