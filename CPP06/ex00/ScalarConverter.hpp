#ifndef SCALAR_CONVERTER_HPP__
#define SCALAR_CONVERTER_HPP__


#include <iostream>
#include <limits>
#include <string>
#include <cmath>
#include <sstream>



typedef enum t_type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO,
    NONE
};

class ScalarConverter
{

        //orthodox form
        ScalarConverter( void );
        ScalarConverter( const ScalarConverter& other );
        ScalarConverter& operator=( const ScalarConverter& other);
        ~ScalarConverter( void );

    public:

        static  void convert( const std::string& literalRep );
};


#endif