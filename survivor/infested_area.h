#ifndef INFESTED_AREA_H
#define INFESTED_AREA_H

#include <boost/random/random_device.hpp>
#include <boost/random/discrete_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_real_distribution.hpp>
using namespace boost;
using namespace boost::random;
class infested_area
{
        int _popsize;
        int _pathdistance;

   protected:
        double _zombstr;

    public:
        infested_area();
        infested_area(int&, int&, double&);
        const int & path_distance() const;
        const double & zombie_strength() const;
        void path_distance(const int&);
        void zombie_strength(const double &);
        virtual double zombie_attack() const;
        double encounterRate(int&) const;        
        const int & population() const;
        virtual const char identifier() = 0;
        

        static const int MAX_PATH_DISTANCE=50;
        static const int MIN_PATH_DISTANCE=10;
        static const int MAX_ZOMBIE_STR=11;
        static const int MIN_ZOMBIE_STR=5;
        static const int MAX_POPULATION=500;
        static const double MIN_ATTACK;
        static const double MAX_ATTACK;
};
#endif
