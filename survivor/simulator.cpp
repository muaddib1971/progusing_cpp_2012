#include "simulator.h"

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

simulator::simulator() : _survivors(vector<survivor*>()), _area(NULL)
{
}

simulator::~simulator()
{
    while(_survivors.size() >  0)
    {
        survivor * surv = _survivors.back();
        _survivors.pop_back();
        delete surv;
    }
    delete _area;
}

void simulator::survivors(vector<survivor*> & survs)
{
    while(_survivors.size() >  0)
    {
        survivor * surv = _survivors.back();
        _survivors.pop_back();
        delete surv;
    }
    _survivors = survs;
}

void simulator::area(infested_area * myarea)
{
    _area=myarea;
}

void simulator::run_tests()
{
    assert(_area);
    assert(this->_survivors.size() > 0);

    for(vector<survivor*>::iterator it = _survivors.begin(); 
        it != _survivors.end(); it++)
    {
        survivor * surv = *it;
        !run_test(_area, surv);
    }
}

bool simulator::run_test(const infested_area * area, survivor * surv)
{
    assert(area);
    assert(surv);
    int prevsteps=0;

    while(surv->location() < area->path_distance())
    {
       int steps = surv->stepsAdvanced();
       (*surv)+=steps;
       int totalsteps = surv->location();
       const hospital * hos = dynamic_cast<const hospital*>(area);
       if(hos)
       {
           unsigned oldhealthinc=prevsteps / hospital::INCREMENT;
           unsigned newhealthinc=totalsteps / hospital::INCREMENT;
           surv->health(surv->health() 
            + newhealthinc - oldhealthinc);
       }
       prevsteps = totalsteps;
       double encrate = area->encounterRate(steps); 
       if(encrate > MIN_ATTACK_RATE)
       {
           double zombattack, survattack;
           zombattack = area->zombie_attack();
           survattack = surv->attack();
           if(zombattack > survattack)
           {
               surv->health(surv->health() - zombattack + survattack);
           }
           if(surv->health() < 0)
           {
               cout << "You died and suck." << endl;
               return false;
           }
       }
    }
    return true;
}
