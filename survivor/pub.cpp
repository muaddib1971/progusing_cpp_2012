#include "pub.h"

char pub::identifier()
{
    return 'P';
}

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
