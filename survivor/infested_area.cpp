#include "infested_area.h"

/**
 * define any constants for this class
 **/
const double infested_area::MIN_ATTACK=0.0;
const double infested_area::MAX_ATTACK=1.0;

/**
 * The default constructor - just a dummy that I would need to insert
 * infested areas into a collection such as a vector or an array.
 */
infested_area::infested_area() 
    : _popsize(0), _pathdistance(0), _zombstr(0.0)
{
}

/**
 * creates a new infested area with the population size, pathdistance 
 * and zombie strength specified.
 **/
infested_area::infested_area(int & popsize, int & pathdist, 
        double & zstren) :
   _popsize(popsize), _pathdistance(pathdist), _zombstr(zstren)
{
}

/**
 * defines the power of a zombie attack.
 **/
double infested_area::zombie_attack() const
{
    // the random number generator
    random_device rand_generator; 

    // a distribution (range) over which we want to generate
    //random numbers
    uniform_real_distribution<> range(MIN_ATTACK, MAX_ATTACK);

    // generate our random double in the range specified
    double rnd_el = range(rand_generator);

    // the value we want is a random number between 0 and the maximum
    // strength a zombie has.
    return rnd_el * _zombstr;
}

/**
 * defines how often we come across a zombie.
 **/
double infested_area::encounterRate(int & steps) const
{
    // the random number generator 
    random_device gen;
    //a range over which we want to generate random numbers
    uniform_real_distribution<> range(MIN_ATTACK, MAX_ATTACK);
    /* generate the random component */
    double rnd_el = range(gen);
    /* calculate the actual encounter rate */
    return rnd_el * ((double)_popsize)/MAX_POPULATION * (1.0/steps);
}

/**
 * getter functions
 **/
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
