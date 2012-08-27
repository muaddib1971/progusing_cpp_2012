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
#if 0
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
#endif

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

double survivor::gen_luck()
{
    random::random_device generator;
    random::uniform_real_distribution<> range(MIN_LUCK, MAX_LUCK);
    double luck = range(generator);
#ifdef DEBUG
    cerr << luck << endl;
#endif
    return luck;
}

int survivor::stepsAdvanced()
{
    random::random_device generator;
    random::uniform_real_distribution<> range(MIN_STEPS, MAX_STEPS);
    return range(generator) * (updatedStamina()/MAX_STAMINA) + 1;
}

int survivor::updatedStamina()
{
    return _stamina * _health / MAX_HEALTH;
}
