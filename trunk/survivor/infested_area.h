#ifndef INFESTED_AREA_H
#define INFESTED_AREA_H
class infested_area
{
        int _popsize;
        int _pathdistance;
        double _zombstr;
        static const int MAX_PATH_DISTANCE=50;
        static const int MIN_PATH_DISTANCE=10;
        static const int MAX_ZOMBIE_STR=11;
        static const int MIN_ZOMBIE_STR=5;

    public:
        infested_area(int&, int&, double&);
        const int & path_distance() const;
        const double & zombie_strength() const;
        //virtual void increment()=0;
        void path_distance(const int&);
        void zombie_strength(const double &);
};
#endif
