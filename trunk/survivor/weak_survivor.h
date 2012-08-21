#include "survivor.h"
class weak_survivor : public survivor
{
    public:
        double ability() const;
        double stress() const;
        char identifier() const;

    private:
        static double const STRESS_FACTOR;
};
