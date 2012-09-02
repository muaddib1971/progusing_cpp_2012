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

class simulator
{
        vector<survivor*>_survivors;
        infested_area * _area;

    public:
        static const int NUM_ARGS=3;
        static const double MIN_ATTACK_RATE;

        simulator();
        void run_tests();
        void survivors(vector<survivor*>&);
        void area(infested_area *);
        bool run_test(const infested_area *, survivor*);
        virtual ~simulator();
};
#endif
