/**************************************************************************
 * COSC 1252/1254 - Programming Using C++ - Assignment 2 Sample Solution.
 * Developed by Paul Miller in collaboration with Daniel Macias
 **************************************************************************/
#include "pub.h"

/**
 * creates a new pub with the parameters specified
 **/
pub::pub(int& pop, int & dist, double & zstr) : 
    infested_area(pop, dist, zstr)
{
}

/**
 * override the zombie_attack() method from the infested_area class.
 *
 * the main difference here is that zombies have bonus strength.
 **/
double pub::zombie_attack() const
{
    random_device device;
    uniform_real_distribution<> range;
    double rnd_el = range(device);
    /* calculate the bonus strength but make sure it is kept in range */
    int str = _zombstr + STR_BONUS;
    if(str > MAX_ZOMBIE_STR)
    {
        str = MAX_ZOMBIE_STR;
    }
    /* calculate the adjusted zombie attack */
    return rnd_el * str;
}

/**
 * return a char that identifies this object as a pub to the system.
 **/
const char pub::identifier() const
{
    return IDENTIFIER;
}

