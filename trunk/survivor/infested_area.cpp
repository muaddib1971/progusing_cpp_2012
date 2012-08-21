#include "infested_area.h"
const int & infested_area::location() const
{
    return _location;
}

const int & infested_area::path_distance() const
{
    return _pathdistance;
}

const double & infested_area::zombie_strength() const
{
    return _zombstr;
}

void infested_area::location(const int& loc)
{
    _location = loc;
}

void infested_area::path_distance(const int& dist)
{
    _pathdistance = dist;
}

void infested_area::zombie_strength(const double & strength)
{
    _zombstr = strength;
}

