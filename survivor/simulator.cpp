#include "simulator.h"


int main(int argc, char** argv)
{
    if(argc != simulator::NUM_ARGS)
    {
        cerr << "Error: incorrect number of arguments" << endl;
        return EXIT_FAILURE;
    }
    simulator sim;
    parser reader;
    if(!reader.parseFile(argv[1], sim))
    {
        return EXIT_FAILURE;
    }
    sim.run_tests();
    return EXIT_SUCCESS;
}

simulator::simulator() : survivors(vector<survivor*>()), area(NULL)
{
}

simulator::~simulator()
{
    while(survivors.size() >  0)
    {
        survivor * surv = survivors.back();
        survivors.pop_back();
        delete surv;
    }
    delete area;
}

void simulator::run_tests()
{
    
}
