#include "survivor.h"
class weak_survivor : public survivor
{
    public:
        double ability() const;
        double stress() const;

        static const char IDENTIFIER = 'W';

    private:
        static double const STRESS_FACTOR;
};
