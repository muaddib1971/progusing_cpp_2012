#ifndef SURVIVOR_H
#define SURVIVOR_H
#include <string>
using namespace std;
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
        static const double MIN_ABILITY;
        static const double MAX_ABILITY;
        static const double MIN_STRESS;
        static const double MAX_STRESS;
        static const double MIN_LUCK;
        static const double MAX_LUCK;
        
        static const char IDENTIFIER='S';

        survivor(int, int, double, double, double, string, int, int);
        double calc_survival() const;

        virtual int stamina() const;
        virtual double ability() const;
        virtual double stress() const;

};
#endif
