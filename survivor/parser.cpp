#include "parser.h"
/* the characters that we will tokenize each line on */
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
    infested_area * area;
    vector<survivor*>survivors;

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

        /* get the infested area  */

        in.getline(c_line, BUFSIZ);
        line = c_line;

        area = parseArea(line);
        if(!area)
        {
            in.close();
            return false;
        }

        /* get each survivor from the file */
        while(in.good())
        {
            survivor * surv=NULL;
            /* get the line of input */
            in.getline(c_line, BUFSIZ);
            line = c_line;
            if(!in.good())
            {
                /* we can do no more processing as the stream is no
                 * longer good
                 */
                break;
            }
            /* parse the line */
            surv = parseSurvivor(line);
            /* if there is a problem we clean up and exit */
            if(!surv)
            {
                in.close();
                return false;
            }
            /* add the survivor to the collection */
            survivors.push_back(surv);
        }
        /* if we get here and we are not at the end of the file, 
         * some other error has occured, normally an operating system
         * error
         */
        if(!in.eof())
        {
            os_error error("Error reading from file");
            error.print_error(cerr);
            in.close();
            return false;
        }
    }
    else
    {
        /* if we failed to open the file, display an error from the 
         * operating system explaining what went wrong
         */
        os_error error("Error reading from file");
        error.print_error(cerr);
        if(in.is_open())
        {
            in.close();
        }
        return false;
    }
    in.close();
    /* verify that the number of survivors specified was correct */
    if(survivors.size() != num_survivors)
    {
        cerr << "Error: there was a mismatch between the number of "
            << "survivors specified and the actual total." << 
            endl;
        return false;
    }
    /* return the data to the simulator class */
    sim.survivors(survivors);
    sim.area(area);
    /* everything went well */
    return true;
}

/**
 * tries to compose an area based on a line passed from the input file.
 * if it fails, it will return NULL
 **/
infested_area * parser::parseArea(string line)
{
    enum simulator::area_type aType;
    int popsize, distance;
    double strength;
    infested_area * area;
    unsigned tok_count = 0;

    /* create the tokenizer */
    tokenizer tok(line, parser::TOKENS);
    /* while there are still more elements to process */
    while(tok.has_next())
    {
        /* get the next token */
        tok_count++;
        string item = tok.next_token();
        try
        {
            /* convert each token and store it in a variable for later */
            switch(tok_count)
            {
                case simulator::AREA_TYPE:
                    aType = (enum simulator::area_type)item[0];
                    if(aType != simulator::PUB && 
                        aType != simulator::HOSPITAL)
                    {
                        cerr << "Error: the area type is not valid."
                            << endl;
                        return NULL;
                    }
                    break;
                case simulator::POPULATION:
                    popsize = lexical_cast<int>(item);
                    break;
                case simulator::DISTANCE:
                    distance = lexical_cast<int>(item);
                    break;
                case simulator::STRENGTH:
                    strength = lexical_cast<double>(item);
                    break;
                default:
                    cerr << "Error: area data has an invalid number "
                        << "of tokens." << endl;
                    return NULL;
            }
        }
        catch(bad_lexical_cast &)
        {
            cerr << "Error: the population data is invalid." << endl;
            return NULL;
        }
    }
    /* create the infested area */
    if(aType == simulator::PUB)
    {
        area = new pub(popsize, distance, strength);
    }
    else 
    {
        area = new hospital(popsize, distance, strength);
    }
    /* validate that everything went ok */
    if(!area->validate())
    {
        cerr << "Error: the data for the area was not within range." 
            << endl;
        return NULL;
    }
    return area;
}

/**
 * parse the string for each survivor, convert the values and validate.
 * If the survivor data is not valid, return NULL
 **/
survivor * parser::parseSurvivor(string line)
{
    tokenizer tok(line, TOKENS);
    unsigned tok_count = 0;
    enum simulator::survivor_type sType;
    string name;
    int health, power, stamina;
    double ability, stress;
    bool luck;
    string token;
    survivor * surv = NULL;

    /* if we get to this point and there are no tokens something bad
     * has happened
     */
    if(!tok.has_next())
    {
        cerr << "There is an error in the line: " << line << endl;
        return false;
    }
    /* iterate over the tokens */
    while(tok.has_next())
    {
        tok_count++;
        token = tok.next_token();
        try
        {
            switch(tok_count)
            {
                /* process each token, converting it and storing it.
                 * If the data is non-numeric, it will be handled by the
                 * lexical_bad_cast exception.
                 */
                case simulator::SURVIVOR_TYPE:
                    sType=(enum simulator::survivor_type)token[0];
                    if(sType != simulator::NORMAL 
                        && sType != simulator::WEAK 
                        && sType != simulator::TRAINED)
                    {
                        cerr << "Error: survivor is not of a valid type." <<
                            endl;
                    }
                    break;
                case simulator::NAME:
                    name = token;
                    break;
                case simulator::HEALTH:
                    health = lexical_cast<int>(token);
                    break;
                case simulator::POWER:
                    power = lexical_cast<int>(token);
                    break;
                case simulator::STAMINA:
                    stamina = lexical_cast<double>(token);
                    break;
                case simulator::ABILITY:
                    ability = lexical_cast<double>(token);
                    break;
                case simulator::STRESS:
                    stress = lexical_cast<double>(token);
                    break;
                case simulator::LUCK:
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
    /* create a survivor based on the type of survivor specified */
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
    /* validate the range of data used to create the survivor */
    if(!surv->validate())
    {
        cerr << "Error: there was a problem with the data for the " 
            << "survivor: " << line << endl;
        delete surv;
        return NULL;
    }
    return surv;
}
