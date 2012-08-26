#include <iostream>
#include <fstream>
#include <cstdlib>
#include "os_error.h"
#include "weak_survivor.h"
#include "trained_survivor.h"
#include "tokenizer.h"
#include "infested_area.h"
#include "pub.h"
#include "hospital.h"
#include <vector>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

class simulator
{
        vector<survivor*>survivors;
        infested_area * area;

    public:
        static const int NUM_ARGS=2;


        static const string TOKENS;

        simulator();
        bool parseFile(char *);

        infested_area * parseArea(string line);
        survivor * parseSurvivor(string line);

        enum survivor_type
        {
            TRAINED=trained_survivor::IDENTIFIER,
            NORMAL=survivor::IDENTIFIER, 
            WEAK=weak_survivor::IDENTIFIER
        };

        enum area_type
        {
            PUB=pub::IDENTIFIER, HOSPITAL=hospital::IDENTIFIER
        };

        enum area_token
        {
            AREA_TYPE=1, POPULATION, DISTANCE, STRENGTH
        };

        enum survivor_token
        {
            SURVIVOR_TYPE=1, NAME, HEALTH, POWER, STAMINA, ABILITY,
            STRESS, LUCK
        };
};
