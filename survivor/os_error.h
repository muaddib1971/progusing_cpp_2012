#include <boost/system/system_error.hpp>
#include <iostream>
#include <string>
#include <cerrno>

using namespace boost::system;
using namespace std;
#ifndef OS_ERROR_H
#define OS_ERROR_H
class os_error
{
    string err_str;
    int error;

    public:
        os_error(string);
        void print_error(ostream &);
};
#endif
