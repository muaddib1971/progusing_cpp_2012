#include "weak_survivor.h"
const double weak_survivor::STRESS_FACTOR = 4.0;

weak_survivor::weak_survivor( string name, int health, int wpower, 
    int stamina, double ability, double stress, bool luck) :

    survivor(name, health, wpower, stamina, ability, stress, luck)

{
}


double weak_survivor::ability() const
{
    return _ability * 0.7;
}

double weak_survivor::stress() const
{
    return _stress / STRESS_FACTOR;
}

