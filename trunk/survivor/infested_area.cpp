#include "infested_area.h"

infested_area::infested_area(int & popsize, int & pathdist, 
        double & zstren) :
   _popsize(popsize), _pathdistance(pathdist), _zombstr(zstren) 
{
}

const int & infested_area::path_distance() const
{
    return _pathdistance;
}

const double & infested_area::zombie_strength() const
{
    return _zombstr;
}

void infested_area::path_distance(const int& dist)
{
    _pathdistance = dist;
}

void infested_area::zombie_strength(const double & strength)
{
    _zombstr = strength;
}

