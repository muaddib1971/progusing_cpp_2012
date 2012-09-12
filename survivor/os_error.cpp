/**************************************************************************
 * COSC 1252/1254 - Programming Using C++ - Assignment 2 Sample Solution.
 * Developed by Paul Miller in collaboration with Daniel Macias
 **************************************************************************/
 #include "os_error.h"

/**
 * creates a new operating system error with the specified pre-message.
 * 
 * This class will retrieve the operating system message for a particular
 * error defined by the errno global variable.
 **/
os_error::os_error(string _string) 
    : err_str(string(_string)), error(errno)
{
}

/**
 * creates an error message based on the error number that was retrieved
 * earlier and sends it to the output stream "out".
 **/
void os_error::print_error(ostream & out)
{
    out << err_str << ": " << error_code( error, get_system_category())
        .message() << endl;
}
