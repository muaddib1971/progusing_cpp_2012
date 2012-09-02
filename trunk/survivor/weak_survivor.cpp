#include "weak_survivor.h"
// define non-integral constants required by this class
const double weak_survivor::STRESS_FACTOR = 4.0;

/**
 * creates a weak survivor based on the parameters passed in.
 **/
weak_survivor::weak_survivor( string name, int health, int wpower, 
    int stamina, double ability, double stress, bool luck) :

    survivor(name, health, wpower, stamina, ability, stress, luck)
{
}


/**
 * overload ability() from the survivor class
 **/
double weak_survivor::ability() const
{
    return _ability * 0.7;
}

/**
 * overload stress from the parent class
 **/
double weak_survivor::stress() const
{
    return _stress / STRESS_FACTOR;
}

