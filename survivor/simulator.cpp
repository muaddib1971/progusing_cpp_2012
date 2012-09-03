#include "simulator.h"
//static constants required for this class
const double simulator::MIN_ATTACK_RATE = 0.5;

int main(int argc, char** argv)
{
    if(argc != simulator::NUM_ARGS)
    {
        cerr << "Error: incorrect number of arguments" << endl;
        return EXIT_FAILURE;
    }
    string option = argv[1];
    string filename = argv[2];
    if(option != "-f")
    {
        cerr << "Error: your arguments are incorrectly formatted." << endl;
        return EXIT_FAILURE;
    }
    simulator sim;
    parser reader;
    if(!reader.parseFile(filename, sim))
    {
        return EXIT_FAILURE;
    }
    sim.run_tests();
    return EXIT_SUCCESS;
}

/**
 * default constructor for this class - create the vector of survivors and
 * set the area to NULL (or no area).
 **/
simulator::simulator() : _survivors(vector<survivor*>()), _area(NULL)
{
}

/**
 * destroy / free any memory allocated for this class
 **/
simulator::~simulator()
{
    /* free memory for each survivor in the system */
    while(_survivors.size() >  0)
    {
        survivor * surv = _survivors.back();
        _survivors.pop_back();
        delete surv;
    }
    /* free memory for the area associated with this class */
    delete _area;
}

/**
 * replace the current array of survivors with a different group.
 **/
void simulator::survivors(vector<survivor*> & survs)
{
    /* free memory for the current vector of survivors */
    while(_survivors.size() >  0)
    {
        survivor * surv = _survivors.back();
        _survivors.pop_back();
        delete surv;
    }
    /* copy across the list of survivors using the vector class'
     * copy constructor
     */
    _survivors = survs;
}

/**
 * set the current area associated with this object
 **/
void simulator::area(infested_area * myarea)
{
    _area=myarea;
}

/**
 * run tests for each survivor
 **/
void simulator::run_tests()
{
    /* ensure that all elements have sane values */
    assert(_area);
    assert(this->_survivors.size() > 0);
    unsigned survcount = 0;

    /* iterate over the vector of survivors. run the test for 
     * each survivor
     */

    cout << "\nInfected area\t\t";
    switch(_area->identifier())
    {
        case PUB:
            cout << "Pub" << endl;
            break;
        case HOSPITAL:
            cout << "Hospital" << endl;
    }
    cout << "Population size\t\t" << _area->population() << endl;
    cout << "Path distance\t\t" << _area->path_distance() << " kilometers" 
        << endl;
    cout << "Zombie strength\t\t" << _area->zombie_strength() 
        << endl << endl;
    cout << "Number of survivors:\t" << _survivors.size() << endl;
    for(vector<survivor*>::iterator it = _survivors.begin(); 
        it != _survivors.end(); it++)
    {
        survcount++;
        cout << "---SURVIVOR #" << survcount << "---" << endl;
        survivor * surv = *it;
        run_test(_area, surv);
    }
}

/**
 * run the test for each survivor. We set the survivor at the beginning
 * of the infested_area and move the survivor along he infested area, 
 * fighting zombies if the encounter_rate > 1/2. We then report on whether
 * each survivor actually manages to get to the end.
 **/
bool simulator::run_test(const infested_area * area, survivor * surv)
{
    /* ensure all pointers are valid */
    assert(area);
    assert(surv);
    /* each round we store how many steps we had reached in order to 
     * deal with the healrate of the hospital class
     */
    int prevsteps=0;

    switch(surv->identifier())
    {
        case NORMAL:
            cout << "Normal ";
            break;
        case TRAINED:
            cout << "Trained ";
            break;
        case WEAK:
            cout << "Weak ";
            break;
    }
    cout << "survivor ID:\t" << surv->name() << endl;
    cout << "Max. health\t\t" << surv->health() << endl;
    cout << "Weapon\t\t\t" << surv->power() << endl;
    cout << "Stamina\t\t\t" << surv->stamina() << endl;
    cout << "Ability\t\t\t" << surv->ability() << endl;
    cout << "Behaviour under stress\t" << surv->stress() << endl;
    if(surv->luck())
    {
        cout << "Luck factor enabled" << endl;
    }
    else
    {
        cout << "Luck factor disabled" << endl;
    }

    /* while we are still inside the infested area */
    while(surv->location() < area->path_distance())
    {
       /* grab the current steps to be advanced */
       int steps = surv->stepsAdvanced();
       /* increment the steps */
       (*surv)+=steps;
       /* grab how many steps along the path is the survivor */
       int totalsteps = surv->location();
       /* we test if the area is a hospital as then we need to increment
        * health of the survivor after 5 steps. It would be nice if we 
        * could do this polymorphically but steps are incremented in the 
        * survivor in my solution and the health bonus is dependent on 
        * area type. One solution would be to store a pointer to the 
        * area in the survivor class and then this could be handled within
        * the survivor class.
        */
       const hospital * hos = dynamic_cast<const hospital*>(area);
       if(hos)
       {
           /* if we are in a hospital, we calculate the size of the
            * increment. Note that if we have not moved up to another
            * increment of five steps, this code will have no effect
            */
           unsigned oldhealthinc=prevsteps / hospital::INCREMENT;
           unsigned newhealthinc=totalsteps / hospital::INCREMENT;
           surv->health(surv->health() 
            + newhealthinc - oldhealthinc);
       }
       /* update the number of previous steps for the next iteration */
       prevsteps = totalsteps;
       /* calculate the probability of an encounter */
       double encrate = area->encounterRate(steps); 
       /* if the encounter probability rises above the threshold, we will
        * have a fight
        */
       if(encrate > MIN_ATTACK_RATE)
       {
           /* retrieve the attack values for the survivor and the zombie */
           double zombattack, survattack;
           zombattack = area->zombie_attack();
           survattack = surv->attack();
           /* only if the zombie's attack rate is higher than the survivor
            * does this have any effect and then only the difference is
            * subtracted from the survivor's health
            */
           if(zombattack > survattack)
           {
               surv->health(surv->health() - zombattack + survattack);
           }
           /* we need to handle the death */
           if(surv->health() < 0)
           {
               cout << "You died and suck." << endl;
               return false;
           }
       }
    }
    /* they got through */
    return true;
}
