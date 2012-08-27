#ifndef SIMULATOR_H
#define SIMULATOR_H
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
#include "parser.h"
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

        simulator();
        void run_tests();
        virtual ~simulator();
};
#endif
