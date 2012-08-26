#include "os_error.h"

os_error::os_error(string _string) 
    : err_str(string(_string)), error(errno)
{
}

void os_error::print_error(ostream & out)
{
    out << err_str << ": " << error_code( error, get_system_category())
        .message() << endl;
}
