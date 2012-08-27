#include "trained_survivor.h"

trained_survivor::trained_survivor( string name, int health, int wpower, 
    int stamina, double ability, double stress, bool luck) :

    survivor(name, health, wpower, stamina, ability, stress, luck)
{
}


int trained_survivor::stamina() const
{
    return _stamina + 15;
}

double trained_survivor::stress() const
{
    return _stress * 0.9;
}

