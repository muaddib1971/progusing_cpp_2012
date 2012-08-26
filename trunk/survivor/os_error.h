#include <boost/system/system_error.hpp>
#include <iostream>
#include <string>
#include <cerrno>

using namespace boost::system;
using namespace std;

class os_error
{
    string err_str;
    int error;

    public:
        os_error(string);
        void print_error(ostream &);
};
