/**************************************************************************
 * COSC 1252/1254 - Programming Using C++ - Assignment 2 Sample Solution.
 * Developed by Paul Miller in collaboration with Daniel Macias
 **************************************************************************/
#include "hospital.h"

/**
 * creates a new hospital object with the population, distance and 
 * zombie strength specified
 */
hospital::hospital(int & pop, int & dist, double & zstr)
    : infested_area(pop, dist, zstr)
{
}

/**
 * return a char that identifies this object as a hospital
 **/
const char hospital::identifier() const
{
    return IDENTIFIER;
}
