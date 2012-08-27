#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <unistd.h>
#include <string>
#include <iomanip>
#include "survivor.h"
#include <boost/lexical_cast.hpp>


survivor * process_options(int argc, char** argv);
double gen_luck();

#define STAMINA 's'
#define LOCATION 'p'
#define ABILITY 'a'
#define STRESS 't'
#define LUCK 'l'
#define MIN_STAMINA 0
#define MAX_STAMINA 100
#define MIN_LOCATION 1
#define MAX_LOCATION 500
#define MIN_ABILITY 0
#define MAX_ABILITY 1
#define MIN_STRESS 0
#define MAX_STRESS 1
#define MIN_LUCK -0.15
#define MAX_LUCK 0.15

using namespace std;
using namespace boost;

