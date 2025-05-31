#ifndef SCALAR_CONVERTER_HPP__
#define SCALAR_CONVERTER_HPP__


#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <cstdio>
#include <iomanip> 
#include <limits>
#include <climits>



typedef enum
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO,
    NONE
}  t_type;

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