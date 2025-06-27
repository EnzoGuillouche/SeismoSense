#include "earthquake.hpp"

Earthquake::Earthquake(float mag, std::vector<float> epi, float dep, float dur)
{
    this->magnitude = mag;
    this->epicenter = epi;
    this->depth = dep;
    this->duration = dur;
}