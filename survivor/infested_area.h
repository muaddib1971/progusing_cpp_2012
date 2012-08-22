class infested_area
{
        int _pathdistance;
        double _zombstr;
        static const int MAX_PATH_DISTANCE=50;
        static const int MIN_PATH_DISTANCE=10;
        static const int MAX_ZOMBIE_STR=11;
        static const int MIN_ZOMBIE_STR=5;

    protected:
        int _location;

    public:
        virtual char identifier() = 0;

        const int & location() const;
        const int & path_distance() const;
        const double & zombie_strength() const;
        void location(const int&);
        virtual void increment()=0;
        void path_distance(const int&);
        void zombie_strength(const double &);
};

