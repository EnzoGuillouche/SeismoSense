#pragma once

#include <vector>

// quantifies how strongly the ground shakes during the earthquake
struct GroundAcceleration
{
    // the force that structures experience
    float PGA; // in g (gravitational acceleration)
    // the maximum speed at which the ground moves
    float PGV; // in centimeters per second (cm/s)
};

class Earthquake
{
private:
    float magnitude;
    std::vector<float> epicenter; // x and y-coordinates of the epicenter
    float depth; // z-coordinates of the epicenter
    float duration; // in seconds (s)

    GroundAcceleration groundAcceleration;
    // and here wave characteristics

public:
    Earthquake(float mag, std::vector<float> epi, float dep, float dur);
    float getMagnitude() const { return this->magnitude; };
    std::vector<float> getEpicenter() const { return this->epicenter; };
    float getDepth() const { return this->depth; };
    float getDuration() const { return this->duration; };
    GroundAcceleration getGroundAcceleration() const { return this->groundAcceleration; };
};
