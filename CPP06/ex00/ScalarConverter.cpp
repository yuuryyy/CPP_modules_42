#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void )
{
}

ScalarConverter::ScalarConverter( const ScalarConverter& other )
{
    *this = other;
}

ScalarConverter&
ScalarConverter::operator=( const ScalarConverter& other )
{
    (void)other;
    return *this;
}

bool
ScalarConverter::isChar(const std::string& literalRep)
{
 
    return (literalRep.length() == 3 && 
            literalRep[0] == '\'' && 
            literalRep[2] == '\'' &&
            isprint(literalRep[1]));
}

bool
ScalarConverter::isInt( const std::string& literalRep )
{
    int    sign = 0;

    if (literalRep[sign] == '+' || literalRep[sign] == '-')
    {
        if ( literalRep.length() == 1)  return false;
        sign++;
    }

    
    


    

}

bool
ScalarConverter::isFloat( const std::string& literalRep )
{
    int pos = 0;

    for (int i = 0; i < literalRep.length(); i++)
    {
        if (!isdigit(literalRep[i]) && (literalRep[i]) != 'f' && literalRep[i] != '.'
            ||(literalRep[i] == 'f' && i != literalRep.length() - 1)
            ||(literalRep[i] == '.' &&( i == 0 || i == literalRep.length() - 1)))
                return false;

        else if (literalRep[i] == '.')
            pos++;
    }
    if (pos != 1)
        return false;

    return true;
}


bool
ScalarConverter::isDouble( const std::string& literalRep )
{

}
// int
// ScalarConverter::error( const std::string& literalRep )
// {
//     for(int i = 0; literalRep[i]; )
// }



















ScalarConverter::~ScalarConverter( void )
{
}