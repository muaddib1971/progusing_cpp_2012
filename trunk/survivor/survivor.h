/**************************************************************************
 * COSC 1252/1254 - Programming Using C++ - Assignment 2 Sample Solution.
 * Developed by Paul Miller in collaboration with Daniel Macias
 **************************************************************************/
#include <boost/random/random_device.hpp>
#include <boost/random/discrete_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_real_distribution.hpp>
#include "validator.h"

#ifndef SURVIVOR_H
#define SURVIVOR_H
#include <string>
using namespace std;
using namespace boost;
using namespace boost::random;

/**
 * class that represents a survivor in the system
 **/
class survivor : public validator
{ 
    protected:
        int _stamina;
        double _ability;
        double _stress;
        bool _luck;

    private:
        string _name;
        int _health;
        int _wpower;

    protected:
        int _location;


    public:
        //struct that simplifies the returning of the mean and 
        //standard deviation in one unit
        struct result
        {
            double mean;
            double stddev;
        };

        //constants required by the survivor limit the range of values
        //that can be passed in.
        static const double ALPHA;
        static const double BETA;
        static const double GAMMA;
        static const double PHI;
        static const double LOCFAC;
        static const double STRESSFAC;

        static const int MIN_STAMINA = 0;
        static const int MAX_STAMINA = 100;
        static const int MIN_LOCATION = 1;
        static const int MAX_LOCATION  = 500;
        static const int MIN_HEALTH=5;
        static const int MAX_HEALTH=10;
        static const int MIN_POWER=5;
        static const int MAX_POWER=10;
        static const int MIN_STEPS=0;
        static const int MAX_STEPS=2;
        static const unsigned NUM_REPEATS=10;
        static const double MIN_ABILITY;
        static const double MAX_ABILITY;
        static const double MIN_STRESS;
        static const double MAX_STRESS;
        static const double MIN_LUCK;
        static const double MAX_LUCK;
        static const double MIN_ATTACK;
        static const double MAX_ATTACK;
        static const double ATTACK_BONUS;
        
        static const char IDENTIFIER='S';

        survivor(string, int , int , int, double , double , bool);

        double gen_luck() const;
        result * calc_survival() const;
        int stepsAdvanced();
        int updatedStamina();
        double attack();
        const bool & luck() ;
        virtual int stamina() const;
        virtual int location() const;
        virtual double ability() const;
        virtual double stress() const;
        virtual int power() const;
        virtual int health() const;
        virtual void health(const int&);
        virtual const char identifier() const;
        result * calc_mean(vector<double>) const;
        string name() const;
        survivor operator+=(int);
        bool validate() const;
};
#endif
