#include "infested_area.h"

class pub: public infested_area
{
    public:
        char identifier();
        void increment();
        pub operator++();
        pub operator++(int);
};
