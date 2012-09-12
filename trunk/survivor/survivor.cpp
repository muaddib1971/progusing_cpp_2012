/**************************************************************************
 * COSC 1252/1254 - Programming Using C++ - Assignment 2 Sample Solution.
 * Developed by Paul Miller in collaboration with Daniel Macias
 **************************************************************************/
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

/**
 * getter functions 
 **/
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

int survivor::health() const
{
    return _health;
}

const char survivor::identifier() const
{
    return IDENTIFIER;
}

/**
 * ensure all class values are within the allowed range
 **/
bool survivor::validate() const
{
    if(_stamina < MIN_STAMINA || _stamina > MAX_STAMINA)
    {
        return false;
    }
    if(_ability < MIN_ABILITY || _ability > MAX_ABILITY)
    {
        return false;
    }
    if(_stress < MIN_STRESS || _stress > MAX_STRESS)
    {
        return false;
    }
    if(_health < MIN_HEALTH || _health > MAX_HEALTH)
    {
        return false;
    }
    if(_wpower < MIN_POWER || _wpower > MAX_POWER)
    {
        return false;
    }
    return true;
}

/**
 * calculate the chances of survival dependent on whether this survivor
 * has luck enabled or not. 
 **/
survivor::result * survivor::calc_survival() const
{
    //the collection of results
    vector<double>results;
    //the survival probability for the current run.
    double survival;
    // the final result - mean and standard deviation
    result * mean = NULL;
    if(_luck)
    {
        /* if luck is enabled then we generate luck NUM_REPEATS times.
         * and store these in a vector. We then calculate mean and standard
         * deviation for this collection of runs.
         */
        for(unsigned count = 0; count < NUM_REPEATS; count++)
        {
            double luck = gen_luck();
            survival = (ALPHA * stamina()) + (BETA - _location/LOCFAC) +
                (GAMMA * ability()) + (PHI - (stress()/STRESSFAC)) + luck;
            if (survival > 1.0)
            {
                survival=1.0;
            }
            results.push_back(survival);
        }
        mean = calc_mean(results);
    }
    else
    {
        survival = (ALPHA * stamina()) + (BETA - _location/LOCFAC) +
            (GAMMA * ability()) + (PHI - (stress()/STRESSFAC));
        if (survival > 1.0)
        {
            survival=1.0;
        }
        mean = new result();
        mean->mean = survival;
        mean->stddev=0;
    }
    return mean;
}

/**
 * generates a random double in the range of allowed luck. Random device
 * is from boost::random and generates random numbers in a non-derministic
 * fashion.
 **/
double survivor::gen_luck() const
{
    random::random_device generator;
    random::uniform_real_distribution<> range(MIN_LUCK, MAX_LUCK);
    double luck = range(generator);
    return luck;
}

/**
 * calculates the number of steps advanced according to the formula
 * specified 
 **/
int survivor::stepsAdvanced()
{
    random_device rand_generator;
    uniform_real_distribution<> range(MIN_STEPS, MAX_STEPS);
    return range(rand_generator) * ((double)(updatedStamina())/MAX_STAMINA)
        + 1;
}

/**
 * calculates the updated stamina based on the formula provided for 
 * assignment 2.
 **/
int survivor::updatedStamina()
{
    return _stamina * (double)_health / MAX_HEALTH;
}

/**
 * increments the current location of the survivor 
 **/
survivor survivor::operator+=(int num)
{
    this->_location += num;
    return *this;
}

/**
 * adjusts the health of the survivor - one of the few setters in this 
 * class as they are unnecesary.
 **/
void survivor::health(const int & newhealth)
{
    _health = newhealth;
}

/**
 * implements the survivor's attack function as per the formula provided
 * for assignment 2.
 **/
double survivor::attack()
{
    random_device gen;
    uniform_real_distribution<> dist(MIN_ATTACK, MAX_ATTACK);
    double rnd_el = dist(gen);
    return rnd_el * (power() + ATTACK_BONUS * ability());
}
        
/**
 * calculates mean and standard deviation for a vector of doubles
 **/
survivor::result * survivor::calc_mean(vector<double> results) const
{
    result * res;
    double total, mean, devs;
    /* find the total of all values in the vector */
    for(vector<double>::iterator it = results.begin(); it < results.end();
        it++)
    {
        total += *it;
    }
    mean = total / results.size();
    /* calculate the deviations - a deviation is the difference between
     * a value and the mean
     */
    vector<double>deviations;
    for(vector<double>::iterator it = results.begin(); it < results.end();
        it++)
    {
        deviations.push_back(*it - mean);
    }
    /* calculate the square of each deviation and add them together */
    for(vector<double>::iterator it = deviations.begin(); 
        it < deviations.end(); it++)
    {
        double value = *it;
        devs +=  value * value;
    }
    /* store the mean and the standard deviation for return */
    res = new result();
    res->mean = mean;
    res->stddev = sqrt(devs/(deviations.size() - 1));
    return res;
}
