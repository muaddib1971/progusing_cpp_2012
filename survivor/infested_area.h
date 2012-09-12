/**************************************************************************
 * COSC 1252/1254 - Programming Using C++ - Assignment 2 Sample Solution.
 * Developed by Paul Miller in collaboration with Daniel Macias
 **************************************************************************/
#ifndef INFESTED_AREA_H
#define INFESTED_AREA_H

#include <boost/random/random_device.hpp>
#include <boost/random/discrete_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_real_distribution.hpp>
#include "validator.h"

using namespace boost;
using namespace boost::random;
/**
 * represents an infested area within the system
 **/
class infested_area : public validator
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
        virtual const char identifier() const = 0;
        bool validate() const;
        

        /* the constants that represent limits imposed on an infested
         * area
         */
        static const int MAX_PATH_DISTANCE=50;
        static const int MIN_PATH_DISTANCE=10;
        static const int MAX_ZOMBIE_STR=11;
        static const int MIN_ZOMBIE_STR=5;
        static const int MIN_POPULATION=1;
        static const int MAX_POPULATION=500;
        static const double MIN_ATTACK;
        static const double MAX_ATTACK;
};
#endif
