#ifndef SCALAR_CONVERTER_HPP__
#define SCALAR_CONVERTER_HPP__


#include <iostream>
#include <limits>
#include <string>
#include <cmath>
#include <sstream>


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

        static void     ConvertChar( const std::string& literalRep );
        static void     ConvertInt( const std::string& literalRep );
        static void     ConvertFloat( const std::string& literalRep );
        static void     ConvertDouble( const std::string& literalRep );

        static void     pseudoHandler( const std::string& literalRep );
        
        static int     error( const std::string& literalRep );

    public:

        static  void convert( const std::string& literalRep );
};


#endif