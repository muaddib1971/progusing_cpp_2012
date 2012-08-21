#include "infested_area.h"
class hospital : public infested_area
{
    public:
        char identifier();
        void increment();
        hospital operator++();
        hospital operator++(int);
};
