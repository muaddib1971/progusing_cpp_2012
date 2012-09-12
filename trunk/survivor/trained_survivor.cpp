/**************************************************************************
 * COSC 1252/1254 - Programming Using C++ - Assignment 2 Sample Solution.
 * Developed by Paul Miller in collaboration with Daniel Macias
 **************************************************************************/
#include "trained_survivor.h"

/**
 * create a new trained survivor based on the parameters passed in.
 **/
trained_survivor::trained_survivor( string name, int health, int wpower, 
    int stamina, double ability, double stress, bool luck) :

    survivor(name, health, wpower, stamina, ability, stress, luck)
{
}

/**
 * override the stamina from the survivor class
 **/
int trained_survivor::stamina() const
{
    return _stamina + 15;
}

/**
 * override stress from the survivor class 
 **/
double trained_survivor::stress() const
{
    return _stress * 0.9;
}

/**
 * return a char that will identify this object as a trained survivor to
 * the system.
 **/
const char trained_survivor::identifier() const
{
    return IDENTIFIER;
}

