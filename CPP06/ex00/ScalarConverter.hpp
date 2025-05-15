#ifndef SCALAR_CONVERTER_HPP__
#define SCALAR_CONVERTER_HPP__


#include <iostream>
#include <limits>
#include <string>
#include <cmath>


class ScalarConverter
{

        //orthodox form
        ScalarConverter( void );
        ScalarConverter( const ScalarConverter& other );
        ScalarConverter& operator=( const ScalarConverter& other);
        ~ScalarConverter( void );

        //helpers

        static bool    isChar( const std::string& literalRep );
        static bool    isInt( const std::string& literalRep );
        static bool    isFloat( const std::string& literalRep );
        static bool    isDouble( const std::string& literalRep );

        static void     ConvertChar(char c);
        static void     ConvertInt(int i);
        static void     ConvertFloat(float f);
        static void     ConvertDouble(double d);

        static bool     pseudoHandler( const std::string& literalRep );
        
        static int     error( const std::string& literalRep );

    public:

        static  void convert( const std::string& literalRep );
};


#endif