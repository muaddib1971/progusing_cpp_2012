/**************************************************************************
 * COSC 1252/1254 - Programming Using C++ - Assignment 2 Sample Solution.
 * Developed by Paul Miller in collaboration with Daniel Macias
 **************************************************************************/
#ifndef VALIDATOR_H
#define VALIDATOR_H
/**
 * represents a class within the system that must provide the validate
 * function in order to ensure that all its values are within allowable
 * ranges. This class essentially operates the same as an interface
 * in java.
 **/
class validator
{
    public:
        virtual bool validate() const = 0;
};
#endif
