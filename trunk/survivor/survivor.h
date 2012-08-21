#ifndef SURVIVOR_H
#define SURVIVOR_H
#include <string>
using namespace std;
class survivor
{
    protected:
        int _stamina;
        int _location;
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

        survivor(int, int, double, double, double, string, int, int);
        double calc_survival() const;

        virtual int stamina() const;
        virtual double ability() const;
        virtual char identifier() const;
        virtual double stress() const;

};
#endif
