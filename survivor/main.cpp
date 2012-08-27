#include "main.h"
#if 0
int main(int argc, char** argv)
{
    survivor * surv = process_options(argc, argv);
    if(!surv)
    {
        return EXIT_FAILURE;
    }
    cout << fixed;
    cout << setprecision(6);
    cout << "Survival rate: " << surv->calc_survival() << endl;
    delete surv;
    return EXIT_SUCCESS;
}
#endif
survivor * process_options(int argc, char** argv)
{
    survivor * surv = NULL;
    int stamina, location;
    double ability, stress, luck;
    const char * options = "s:p:a:t:l";
    int ch;
    string instr;

    opterr=0;
    luck = 0.0;
    while((ch = getopt(argc, argv, options)) !=EOF)
    {
        try
        {
            switch(ch)
            {
                case STAMINA:
                    instr = optarg;
                    stamina = lexical_cast<int>(instr);
                    if(stamina < MIN_STAMINA || stamina > MAX_STAMINA)
                    {
                        cerr << "Error: stamina is out of range." << endl;
                        return NULL;
                    }
                    break;
                case LOCATION: 
                    instr = optarg;
                    location = lexical_cast<int>(instr);
                    if(location < MIN_LOCATION || location > MAX_LOCATION)
                    {
                        cerr << "Error: location is out of range." << endl;
                        return NULL;
                    }
                    break;
                case ABILITY:
                    instr = optarg;
                    ability = lexical_cast<double>(instr);
                    if(ability < MIN_ABILITY || ability > MAX_ABILITY)
                    {
                        cerr << "Error: ability is out of range." << endl;
                        return NULL;
                    }
                    break;
                case STRESS:
                    instr = optarg;
                    stress = lexical_cast<double>(instr);
                    if(stress < MIN_STRESS || stress > MAX_STRESS)
                    {
                        cerr << "Error: stress is out of range." << endl;
                        return NULL;
                    }
                    break;
                case LUCK:
                    luck = gen_luck();
                    break;
                case '?':
                    if(optopt == STAMINA || optopt == LOCATION || 
                        optopt == ABILITY || optopt == STRESS)
                    {
                        cerr << "Error: Missing Argument." << endl;
                    }
                    else if(isprint(optopt))
                    {
                        cerr << "Error: Unknown option: -" 
                            << optopt << endl;
                    }
                    else
                    {
                        cerr << "Error: Unknown Option Character: -" <<
                            optopt << endl;
                    }
                    return NULL;
                default:
                    return NULL;

            }
        }
        catch(bad_lexical_cast &)
        {
            cerr << "Error: your command line arguments are not valid." 
                << endl;
            return NULL;
        }
    }

    //at this point all values should have been retrieved.

#if 0
    surv = new survivor(stamina, location, ability, stress, luck);
#endif
    return surv;
}


