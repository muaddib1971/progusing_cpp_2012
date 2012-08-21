#include "trained_survivor.h"

int trained_survivor::stamina() const
{
    return _stamina + 15;
}

double trained_survivor::stress() const
{
    return _stress * 0.9;
}

char trained_survivor::identifier() const
{
    return 'T';
}
