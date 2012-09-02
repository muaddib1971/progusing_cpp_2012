#include "infested_area.h"
#ifndef PUB_H
#define PUB_H
class pub: public infested_area
{
    public:
        pub(int&, int&, double&);
        static const char IDENTIFIER='P';
        virtual double zombie_attack() const;
};
#endif
