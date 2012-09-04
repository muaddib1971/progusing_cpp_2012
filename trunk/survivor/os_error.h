#include <boost/system/system_error.hpp>
#include <iostream>
#include <string>
#include <cerrno>

using namespace boost::system;
using namespace std;
#ifndef OS_ERROR_H
#define OS_ERROR_H

/**
 * represents an operating system error - this is used much the same way
 * perror() is used in C: You provide a prefix error message and the rest
 * of the message is populated by the operating system.
 **/
class os_error
{
    string err_str;
    int error;

    public:
        os_error(string);
        void print_error(ostream &);
};
#endif
