#include "infested_area.h"
class hospital : public infested_area
{
    public:
        hospital(int&, int&, double&);
        static const char IDENTIFIER='H';
#if 0
        void increment();
        hospital operator++();
        hospital operator++(int);
#endif
};
