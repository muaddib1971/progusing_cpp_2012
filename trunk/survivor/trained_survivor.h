#ifndef TRAINED_SURVIVOR_H
#define TRAINED_SURVIVOR_H
#include "survivor.h"
class trained_survivor : public survivor
{
    public:
        int stamina() const;
        double stress() const;
        static const char IDENTIFIER='T';
        trained_survivor( string, int, int , int , double , double , bool); 
};
#endif
