#ifndef PARSER_H
#define PARSER_H
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
#include "simulator.h"
#include <vector>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;
class simulator; 

/**
 * the class that does the parsing of the file passed to the simulator
 **/
class parser
{
    public: 
        infested_area * parseArea(string line);
        survivor * parseSurvivor(string line);
        bool parseFile(string , simulator & );

        static const string TOKENS;
};
#endif
