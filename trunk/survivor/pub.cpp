#include "pub.h"

pub::pub(int& pop, int & dist, double & zstr) : 
    infested_area(pop, dist, zstr)
{
}

#if 0
void pub::increment()
{
    (*this)++;
}


pub pub::operator++()
{
    this->_location++;
    return *this;
}

pub pub::operator++(int)
{
    pub mypub = *this;
    (*this)++;
    return mypub;
}
#endif
