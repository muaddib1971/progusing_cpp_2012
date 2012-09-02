#include "pub.h"

pub::pub(int& pop, int & dist, double & zstr) : 
    infested_area(pop, dist, zstr)
{
}

double pub::zombie_attack() const
{
    random_device device;
    uniform_real_distribution<> range;
    double rnd_el = range(device);
    int str = _zombstr + 1;
    if(str > MAX_ZOMBIE_STR)
    {
        str = MAX_ZOMBIE_STR;
    }
    return rnd_el * str;
}

