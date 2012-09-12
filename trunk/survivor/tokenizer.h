/**************************************************************************
 * COSC 1252/1254 - Programming Using C++ - Assignment 2 Sample Solution.
 * Developed by Paul Miller in collaboration with Daniel Macias
 **************************************************************************/
#include <string>
#include <cstdio>
using namespace std;
#ifndef TOKENIZER
#define TOKENIZER

/**
 * tokenizes a string according to the delimiters passed in.
 */
class tokenizer{
    string main_string;///<the string being tokenized
    string delimiters;///<the delimiters to tokenize on.
    string::size_type last_loc; ///<the location of the last token

 public:
    tokenizer(string,string);///<create a tokenizer
    string next_token();///<get the next token from the string
    bool has_next();///<are there any more tokens?
};
#endif

