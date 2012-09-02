#include "infested_area.h"
#ifndef HOSPITAL_H
#define HOSPITAL_H
class hospital : public infested_area
{
    public:
        hospital(int&, int&, double&);
        static const char IDENTIFIER='H';
        static const int INCREMENT=5;
};
#endif
