#include "hospital.h"

hospital::hospital(int & pop, int & dist, double & zstr)
    : infested_area(pop, dist, zstr)
{
}

#if 0
void hospital::increment()
{
    (*this)++;
    if(_location % 5 == 0)
    {

    }
}

hospital hospital::operator++()
{
    hospital hosp = *this;
    hosp._location++;
    return hosp;
}

hospital hospital::operator++(int)
{
    hospital hosp = *this;
    (*this)++;
    return hosp;
}
#endif
