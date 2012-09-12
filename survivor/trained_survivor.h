/**************************************************************************
 * COSC 1252/1254 - Programming Using C++ - Assignment 2 Sample Solution.
 * Developed by Paul Miller in collaboration with Daniel Macias
 **************************************************************************/
#ifndef TRAINED_SURVIVOR_H
#define TRAINED_SURVIVOR_H
#include "survivor.h"

/**
 * represents a trained survivor within the system
 **/
class trained_survivor : public survivor
{
    public:
        int stamina() const;
        double stress() const;
        static const char IDENTIFIER='T';
        trained_survivor( string, int, int , int , double , double , bool); 
        const char identifier() const;
};
#endif
