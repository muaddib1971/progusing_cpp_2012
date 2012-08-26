#include "infested_area.h"

class pub: public infested_area
{
    public:
        pub(int&, int&, double&);
        static const char IDENTIFIER='P';
#if 0
        void increment();
        pub operator++();
        pub operator++(int);
#endif
};
