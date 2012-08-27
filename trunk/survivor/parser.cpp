#include "parser.h"

const string parser::TOKENS=" ";

/**
 * simulator::parseFile() - read in each line of the file and 
 * tokenize it, storing a 'survivor' object based on it in the 
 * 'survivors' vector.
 * @param filename - the file to open
 * @returns false when there has been an error.
 */
bool parser::parseFile(string filename, simulator & sim)
{
    /* open the file */
    ifstream in(filename.c_str());
    if(!in.is_open())
    {
        os_error error("Error opening file");
        error.print_error(cerr);
        return false;
    }
    /* while there is more to read and there has been no error, 
     * keep reading*/
    unsigned num_survivors;
    char c_line[BUFSIZ];
    string line;

    /* get the number of survivors */
    in.getline(c_line, BUFSIZ);
    if(in.good())
    {
        line = c_line;
        try
        {
            num_survivors = lexical_cast<unsigned>(line);
        }
        catch(bad_lexical_cast &)
        {
            cerr << "Error: the number of survivors was not numeric." 
                << endl;
            return false;
        }

        /* get the infested area type */

        in.getline(c_line, BUFSIZ);
        line = c_line;

        while(in.good())
        {
            survivor * surv=NULL;
            in.getline(c_line, BUFSIZ);
            line = c_line;
            surv = parseSurvivor(line);
            
        }
        if(in.bad() || in.fail())
        {
            os_error error("Error reading from file");
            error.print_error(cerr);
            return false;
        }
    }
    else
    {
        os_error error("Error reading from file");
        error.print_error(cerr);
        return false;
    }
    in.close();
    return true;
}


infested_area * parser::parseArea(string line)
{
    enum area_type aType;
    int popsize, distance;
    double strength;
    infested_area * area;
    unsigned tok_count = 0;

    tokenizer tok(line, parser::TOKENS);
    while(tok.has_next())
    {
        tok_count++;
        string item = tok.next_token();
        try
        {
            switch(tok_count)
            {
                case AREA_TYPE:
                    aType = (enum area_type)item[0];
                    if(aType != PUB && aType != HOSPITAL)
                    {
                        cerr << "Error: the area type is not valid."
                            << endl;
                        return false;
                    }
                    break;
                case POPULATION:
                    popsize = lexical_cast<int>(item);
                    break;
                case DISTANCE:
                    distance = lexical_cast<int>(item);
                    break;
                case STRENGTH:
                    strength = lexical_cast<double>(item);
                    break;
                default:
                    cerr << "Error: area data has an invalid number "
                        << "of tokens." << endl;
                    return false;
            }
        }
        catch(bad_lexical_cast &)
        {
            cerr << "Error: the population data is invalid." << endl;
            return false;
        }
        if(aType == PUB)
        {
            area = new pub(popsize, distance, strength);
        }
        else
        {
            area = new hospital(popsize, distance, strength);
        }
    }
    return area;
}

survivor * parser::parseSurvivor(string line)
{
    tokenizer tok(line, TOKENS);
    unsigned tok_count = 0;
    enum survivor_type sType;
    string name;
    int health, power, stamina;
    double ability, stress;
    bool luck;
    string token;
    survivor * surv = NULL;

    if(!tok.has_next())
    {
        cerr << "There is an error in the line: " << line << endl;
        return false;
    }
    while(tok.has_next())
    {
        tok_count++;
        token = tok.next_token();
        try
        {
            switch(tok_count)
            {
                case SURVIVOR_TYPE:
                    sType=(enum survivor_type)token[0];
                    if(sType != NORMAL && sType != WEAK && sType != TRAINED)
                    {
                        cerr << "Error: survivor is not of a valid type." <<
                            endl;
                    }
                    break;
                case NAME:
                    name = token;
                    break;
                case HEALTH:
                    health = lexical_cast<int>(token);
                    if(health < survivor::MIN_HEALTH || 
                        health > survivor::MAX_HEALTH)
                    {
                        cerr << "Error: health is out of range: " << line
                            << endl;
                        return NULL;
                    }
                    break;
                case POWER:
                    power = lexical_cast<int>(token);
                    if(power < survivor::MIN_POWER ||
                        power > survivor::MAX_POWER)
                    {
                        cerr << "Error: power is out of range: " << line
                            << endl;
                            return NULL;
                    }
                    break;
                case STAMINA:
                    stamina = lexical_cast<double>(token);
                    if(stamina < survivor::MIN_STAMINA || 
                        stamina > survivor::MAX_STAMINA)
                    {
                        cerr << "Error: stamina is out of range: " << line
                            << endl;
                        return NULL;
                    }
                    break;
                case ABILITY:
                    ability = lexical_cast<double>(token);
                    if(ability < survivor::MIN_ABILITY ||
                        ability > survivor::MAX_ABILITY)
                    {
                        cerr << "Error: ability is out of range: " << line
                            << endl;
                        return NULL;
                    }
                    break;
                case STRESS:
                    stress = lexical_cast<double>(token);
                    if(stress < survivor::MIN_STRESS ||
                        stress > survivor::MAX_STRESS)
                    {
                        cerr << "Error: stress is out of range: " << line
                            << endl;
                        return NULL;
                    }
                    break;
                case LUCK:
                    if(token == "true")
                    {
                        luck = true;
                    }
                    else if(token == "false")
                    {
                        luck = false;
                    }
                    else
                    {
                        cerr << "Error: invalid luck value: " << token 
                            << endl;
                        return NULL;
                    }
                    break;
                default:
                    cerr << "Error: there are too many tokens." << endl;
                    return NULL;
            }
        }
        catch(bad_lexical_cast & )
        {
            cerr << "Error: the following survivor's data is invalid: " <<
                line << endl;
            return NULL;
        }
    }
    switch (sType)
    {
        case trained_survivor::IDENTIFIER:
            surv = new trained_survivor(name, health, power, stamina, 
                       ability, stress, luck);
            break;
        case survivor::IDENTIFIER:
            surv = new survivor(name, health, power, stamina, 
                       ability, stress, luck);
            break;
        case weak_survivor::IDENTIFIER:
            surv = new weak_survivor(name, health, power, stamina, 
                       ability, stress, luck);
            break;
        default:
            cerr << "Error: " << sType << 
                " is not a valid survivor type." << endl;
            return NULL;
    }
   return surv;
}
