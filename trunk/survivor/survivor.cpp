#include "survivor.h"

const double survivor::ALPHA=7/2000.0;
const double survivor::BETA=1/4.0;
const double survivor::GAMMA=0.2;
const double survivor::PHI=0.25;
const double survivor::LOCFAC=2500.0;
const double survivor::STRESSFAC=4.0;

survivor::survivor(int stamina, int location, double ability, 
    double stress, double luck, string name, int health, int wpower) 
    : _stamina(stamina), _location(location),
    _ability(ability), _stress(stress), _luck(luck), _name(name), 
    _health(health), _wpower(wpower)
{

}

double survivor::calc_survival() const
{
    double survival;
    survival = (ALPHA * stamina()) + (BETA - _location/LOCFAC) + 
        (GAMMA * ability()) + (PHI - (stress()/STRESSFAC)) + _luck;
    if (survival > 1.0)
    {
        survival=1.0;
    }
    return survival;
}

int survivor::stamina() const
{
    return _stamina;
}

double survivor::ability() const
{
    return _ability;
}
        
char survivor::identifier() const
{
    return 'S';
}
        
double survivor::stress() const
{
    return _stress;
}
