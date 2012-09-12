/**************************************************************************
 * COSC 1252/1254 - Programming Using C++ - Assignment 2 Sample Solution.
 * Developed by Paul Miller in collaboration with Daniel Macias
 **************************************************************************/
#include "infested_area.h"
#ifndef HOSPITAL_H
#define HOSPITAL_H
/**
 * represents a hospital within the system.
 **/
class hospital : public infested_area
{
    public:
        hospital(int&, int&, double&);
        static const char IDENTIFIER='H';
        //represents the size of the increment before we need to 
        //increase the health of a survivor.
        static const int INCREMENT=5;
        const char identifier() const;
};
#endif
