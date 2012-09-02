#include "infested_area.h"

const double infested_area::MIN_ATTACK=0.0;
const double infested_area::MAX_ATTACK=1.0;

infested_area::infested_area() 
    : _popsize(0), _pathdistance(0), _zombstr(0.0)
{
}

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

double infested_area::zombie_attack() const
{
    random_device rand_generator;    
    uniform_real_distribution<> range(MIN_ATTACK, MAX_ATTACK);
    double rnd_el = range(rand_generator);
    return rnd_el * _zombstr;
}

double infested_area::encounterRate(int & steps) const
{
    random_device gen;
    uniform_real_distribution<> range(MIN_ATTACK, MAX_ATTACK);
    double rnd_el = range(gen);
    return rnd_el * ((double)_popsize)/MAX_POPULATION * (1.0/steps);
}

