#include "hospital.h"

char hospital::identifier()
{
    return 'H';
}

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
