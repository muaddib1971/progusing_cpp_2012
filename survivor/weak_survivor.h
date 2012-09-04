#include "survivor.h"
#ifndef WEAK_SURVIVOR_H
#define WEAK_SURVIVOR_H
/**
 * represents a weak survivor within the system
 **/
class weak_survivor : public survivor
{
    public:
        double ability() const;
        double stress() const;

        static const char IDENTIFIER = 'W';

        weak_survivor( string, int, int, int , double , double , bool );
        const char indentifier() const;

    private:
        static double const STRESS_FACTOR;
};
#endif
