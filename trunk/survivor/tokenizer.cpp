/**************************************************************************
 * COSC 1252/1254 - Programming Using C++ - Assignment 2 Sample Solution.
 * Developed by Paul Miller in collaboration with Daniel Macias
 **************************************************************************/
#include "tokenizer.h"

/**
 * creates a new tokenizer to tokenize the string 'line' using the 
 * delimiters contained in delims.
 *
 * @param line the line to tokenize
 * @param delims the delimiters to tokenize the line on.
 */
tokenizer::tokenizer(string line, string delims) : main_string(line), 
                                                   delimiters(delims),
                                                   last_loc(0)
{
    //lastloc is the location of the last delimiter. So, we set it to 0
    //to begin with.
}

/**
 * determines whether the string has more tokens to retrieve
 * @return bool defining whether there are more tokens.
 */
bool tokenizer::has_next()
{
    //find the location of the next token
    string::size_type loc = 
        main_string.find_first_not_of(delimiters, last_loc);
    //if we have reached the end of the tokens
    if(loc == string::npos)
        {
            //let the calling code know there are no more tokens.
            return false;
        }
    //otherwise let the calling code know there are more tokens.
    return true;
}

/**
 * retrieves the next token from the string being tokenized
 *
 * @return string the next token
 */
string tokenizer::next_token()
{
    //find the next character which is not a delimiter
    string::size_type loc = main_string.find_first_not_of(delimiters, 
                                                          last_loc);
    //find the next character that is a delimiter
    string::size_type next_loc = main_string.find_first_of(delimiters, 
                                                           loc);
    char word[BUFSIZ]={0};
    //copy the token from the original string to the string that will be 
    //returned
    string::size_type num_bytes = 
        main_string.copy(word, next_loc - loc, loc);
    //zero terminate the string
    word[num_bytes]=0;
    string ret_val(word);
    //store the location of the last delimiter encountered
    last_loc = next_loc;
    //return the token
    return ret_val;
}
