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
const double survivor::MIN_ATTACK=0.0;
const double survivor::MAX_ATTACK = 1.0;
const double survivor::ATTACK_BONUS=0.3;

survivor::survivor( string name, int health, int wpower, int stamina, 
	double ability, double stress, bool luck) 
    : _stamina(stamina), 
    _ability(ability), _stress(stress), _luck(luck), _name(name), 
    _health(health), _wpower(wpower), _location(0)
{

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

int survivor::location() const
{
    return _location;
}

int survivor::power() const
{
    return _wpower;
}

string survivor::name() const
{
    return _name;
}


const bool & survivor::luck()
{
    return _luck;
}

double survivor::gen_luck()
{
    random::random_device generator;
    random::uniform_real_distribution<> range(MIN_LUCK, MAX_LUCK);
    double luck = range(generator);
    return luck;
}

int survivor::stepsAdvanced()
{
    random_device rand_generator;
    uniform_real_distribution<> range(MIN_STEPS, MAX_STEPS);
    return range(rand_generator) * ((double)(updatedStamina())/MAX_STAMINA)
        + 1;
}

int survivor::updatedStamina()
{
    return _stamina * (double)_health / MAX_HEALTH;
}

survivor survivor::operator+=(int num)
{
    this->_location += num;
    return *this;
}

int survivor::health() const
{
    return _health;
}

void survivor::health(const int & newhealth)
{
    _health = newhealth;
}

double survivor::attack()
{
    random_device gen;
    uniform_real_distribution<> dist(MIN_ATTACK, MAX_ATTACK);
    double rnd_el = dist(gen);
    return rnd_el * (power() + ATTACK_BONUS * ability());
}

const char survivor::identifier() const
{
    return IDENTIFIER;
}
