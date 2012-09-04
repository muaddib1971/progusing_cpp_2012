#ifndef VALIDATOR_H
#define VALIDATOR_H
/**
 * represents a class within the system that must provide the validate
 * function in order to ensure that all its values are within allowable
 * ranges. This class essentially operatates the same as an interface
 * in java.
 **/
class validator
{
    public:
        virtual bool validate() const = 0;
};
#endif
