/**************************************************************************
 * COSC 1252/1254 - Programming Using C++ - Assignment 2 Sample Solution.
 * Developed by Paul Miller in collaboration with Daniel Macias
 **************************************************************************/
#include "infested_area.h"
#ifndef PUB_H
#define PUB_H

/**
 * represents a pub within the system.
 **/
class pub: public infested_area
{
    public:
        pub(int&, int&, double&);
        static const char IDENTIFIER='P';
        /* the strength bonus given to zombies */
        static const int STR_BONUS = 1;
        virtual double zombie_attack() const;
        const char identifier() const;
};
#endif
