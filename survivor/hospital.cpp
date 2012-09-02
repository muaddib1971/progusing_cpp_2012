#include "hospital.h"

/**
 * creates a new hospital object with the population, distance and 
 * zombie strength specified
 */
hospital::hospital(int & pop, int & dist, double & zstr)
    : infested_area(pop, dist, zstr)
{
}
