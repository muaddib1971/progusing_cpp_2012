#include <boost/random/random_device.hpp>
#include <boost/random/discrete_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_real_distribution.hpp>

#ifndef SURVIVOR_H
#define SURVIVOR_H
#include <string>
using namespace std;
using namespace boost;
using namespace boost::random;
class survivor
{ 
    protected:
        int _stamina;
        double _ability;
        double _stress;
        double _luck;

    private:
        string _name;
        int _health;
        int _wpower;

    protected:
        int _location;


    public:
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

        double gen_luck();
        int stepsAdvanced();
        int updatedStamina();
        double attack();
        virtual int stamina() const;
        virtual int location() const;
        virtual double ability() const;
        virtual double stress() const;
        virtual int power() const;
        virtual int health() const;
        virtual void health(const int&);
        survivor operator+=(int);
};
#endif
