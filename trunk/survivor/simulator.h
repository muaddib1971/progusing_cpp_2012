/**************************************************************************
 * COSC 1252/1254 - Programming Using C++ - Assignment 2 Sample Solution.
 * Developed by Paul Miller in collaboration with Daniel Macias
 **************************************************************************/
#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "os_error.h"
#include "weak_survivor.h"
#include "trained_survivor.h"
#include "infested_area.h"
#include "pub.h"
#include "hospital.h"
#include "parser.h"
#include <vector>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

/**
 * runs the tests that are displayed to the user
 **/
class simulator
{
        vector<survivor*>_survivors;
        infested_area * _area;
        streambuf *outbuff, *backup;
        ofstream output;
        static const string OUTPUT;

    public:
        static const int NUM_ARGS=3;
        static const double MIN_ATTACK_RATE;
        static const unsigned PERCENT=100;

        simulator();
        void run_tests();
        void survivors(vector<survivor*>&);
        void area(infested_area *);
        bool run_test(const infested_area *, survivor*);
        virtual ~simulator();

        /* enumerations that provide constants for the simulator and 
         * other associated classes
         */

         //the type of survivor based on the indentifier char
        enum survivor_type
        {
            TRAINED=trained_survivor::IDENTIFIER,
            NORMAL=survivor::IDENTIFIER, 
            WEAK=weak_survivor::IDENTIFIER
        };

        //the type of area based on the identifier char
        enum area_type
        {
            PUB=pub::IDENTIFIER, HOSPITAL=hospital::IDENTIFIER
        };

        //enumeration that simplifies the processing of tokens for an 
        //area.
        enum area_token
        {
            AREA_TYPE=1, POPULATION, DISTANCE, STRENGTH
        };

        //enumeration that simplifies the processing of token for reading
        //in a survivor from the file
        enum survivor_token
        {
            SURVIVOR_TYPE=1, NAME, HEALTH, POWER, STAMINA, ABILITY,
            STRESS, LUCK
        };
};
#endif
