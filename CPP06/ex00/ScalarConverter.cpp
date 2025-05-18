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
            literalRep[2] == '\'');
}

bool
ScalarConverter::isInt( const std::string& literalRep )
{
    bool    sign = false;

    if (literalRep[sign] == '+' || literalRep[sign] == '-')
    {
        if ( literalRep.length() == 1)  return false;
        sign = true;
    }

    for (int i = sign; i < literalRep.length(); i++)
        if (!isdigit(literalRep[i])) return false;

    char *end;
    long num = strtol(literalRep.c_str(), &end, 10);
    if (*end != 0) return false;
    if (num > INT32_MAX || num < INT32_MIN) return false;

    return true;
}

bool
ScalarConverter::isFloat( const std::string& literalRep )
{
    bool point = false;
    bool sign  = false;
    bool    f = false;


    if (literalRep == "-inff" || literalRep == "+inff" || literalRep == "nanf") return true;

    if (literalRep[sign] == '+' || literalRep[sign] == '-')
    {
        if ( literalRep.length() == 1)  return false;
        sign = true;
    }

    for (int i = sign; i < literalRep.length(); i++)
    {
        if (!isdigit(literalRep[i]))
        {
            if (literalRep[i] == '.')
            {
                if (point || i == 0 || (i == 1 && sign) || i == literalRep.length() - 1)
                    return false;
                point = true;
            }
            else if (literalRep[i] == 'f')
            {
                if (i != literalRep.length() - 1 || !literalRep[i - 1] || !isdigit(literalRep[i - 1]))
                    return false;
                f = true;
            }

        }

        else if (!isdigit(literalRep[i])) return false;
    }

    if (!f || !point)
        return false;
    
    char *end;
    strtof(literalRep.c_str(), &end);
    if (*end != 'f' || *(end + 1) != 0) return false;

    return true;
    
}


bool
ScalarConverter::isDouble( const std::string& literalRep )
{
    bool point = false;
    bool sign  = false;

    if (literalRep == "-inf" || literalRep == "+inf" || literalRep == "nan") return true;

    if (literalRep[sign] == '+' || literalRep[sign] == '-')
    {
        if ( literalRep.length() == 1)  return false;
        sign = true;
    }

    for (int i = sign; i < literalRep.length(); i++)
    {
        if (!isdigit(literalRep[i]))
        {
            if (literalRep[i] == '.')
            {
                if (point || i == 0 || (i == 1 && sign) || i == literalRep.length() - 1)
                    return false;
                point = true;
            }

        }
        else if (!isdigit(literalRep[i])) return false;
    }

    if (!point) return false;
    
    char *end;
    strtod(literalRep.c_str(), &end);
    if (*(end ) != 0)   return false;

    return true;
    
}

void
ScalarConverter::ConvertChar( const std::string& literalRep )
{

    char c = literalRep[1];
    std::cout << "Char : ";
    if (isprint(c)) std::cout << '\'' << c << "\'" ;
    else            std::cout << "Non displayable";
    std::cout << std::endl;

    std::cout << "Int : " << static_cast<int>(c) << std::endl;

    std::cout << "Float : " << static_cast<float>(c);
    if (static_cast<float>(c) == static_cast<int>(c))   std::cout << ".0f";
    std::cout << std::endl;

    std::cout << "Double : " << static_cast<double>(c) << std::endl;
    if (static_cast<double>(c) == static_cast<int>(c))   std::cout << ".0";
    std::cout << std::endl;
}

void
ScalarConverter::ConvertInt( const std::string& literalRep )
{
    int i;
    std::istringstream   extract(literalRep);

    extract >> i;

    if (extract.fail() || !extract.eof())
    {
        std::cout << "Char: Impossible\nInt: Impossible\n"
                  << "Float: Impossible\nDouble: Impossible\n";
        return ;
    }

    char    c = static_cast<char>(i);

    std::cout << "Char : ";
    if (isprint(c) && isascii(i)) 
        std::cout << '\'' << c << "\'" ;
    else if (!isascii(i))
        std::cout << "Impossible";

    else   
        std::cout << "Non displayable";
    std::cout << std::endl;

    std::cout << "Int : " << i << std::endl;

    std::cout << "Float : " << static_cast<float>(i);
    if (static_cast<float>(i) == static_cast<int>(i))   std::cout << ".0f";
    std::cout << std::endl;

    std::cout << "Double : " << static_cast<double>(i) << std::endl;
    if (static_cast<double>(i) == static_cast<int>(i))   std::cout << ".0";
    std::cout << std::endl;
}

void
ScalarConverter::ConvertFloat( const std::string& literalRep )
{
    float  f = strtof(literalRep.c_str(), NULL);
    char c = static_cast<char>(f);

    if (isprint(c))
        std::cout << '\'' << c << "\'" ;
    else   
        std::cout << "Non displayable";
    std::cout << std::endl;

    std::cout << "Int : " << static_cast<int>(f) << std::endl;

    std::cout << "Float : " << static_cast<float>(i);
    if (static_cast<float>(i) == static_cast<int>(i))   std::cout << ".0f";
    std::cout << std::endl;

    std::cout << "Double : " << static_cast<double>(i) << std::endl;
    if (static_cast<double>(i) == static_cast<int>(i))   std::cout << ".0";
    std::cout << std::endl;
}
// int
// ScalarConverter::error( const std::string& literalRep )
// {
//     for(int i = 0; literalRep[i]; )
// }




















ScalarConverter::~ScalarConverter( void )
{
}