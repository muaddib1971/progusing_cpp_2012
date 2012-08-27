#include "survivor.h"

const double survivor::ALPHA=7/2000.0;
const double survivor::BETA=1/4.0;
const double survivor::GAMMA=0.2;
const double survivor::PHI=0.25;
const double survivor::LOCFAC=2500.0;
const double survivor::STRESSFAC=4.0;

const double survivor::MIN_ABILITY = 0;
const double survivor::MAX_ABILITY = 1;
const double survivor::MIN_STRESS = 0;
const double survivor::MAX_STRESS = 1;
const double survivor::MIN_LUCK = -0.15;
const double survivor::MAX_LUCK = 0.15;

survivor::survivor( string name, int health, int wpower, int stamina, 
	double ability, double stress, bool luck) 
    : _stamina(stamina), 
    _ability(ability), _stress(stress), _luck(luck), _name(name), 
    _health(health), _wpower(wpower)
{

}

double survivor::calc_survival() const
{
    double survival;
#if 0
    survival = (ALPHA * stamina()) + (BETA - _location/LOCFAC) + 
        (GAMMA * ability()) + (PHI - (stress()/STRESSFAC)) + _luck;
    if (survival > 1.0)
    {
        survival=1.0;
    }
#endif
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
        
double survivor::stress() const
{
    return _stress;
}
