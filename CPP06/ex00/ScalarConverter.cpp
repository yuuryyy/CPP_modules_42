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

static bool
isInt( const std::string& literalRep )
{
    bool    sign = false;

    if (literalRep[sign] == '+' || literalRep[sign] == '-')
    {
        if ( literalRep.length() == 1)  return false;
        sign = true;
    }

    for (int i = sign; i < literalRep.length(); i++)
        if (!isdigit(literalRep[i])) return false;

    return true;
}

static t_type get_type( const std::string& literalRep )
{
    if (literalRep.length() == 3 && literalRep[0] == '\''
        && literalRep[3] == '\'' && (isascii(literalRep[1])))
        return CHAR;
    
    else if (isInt(literalRep))
        return INT;

    if (literalRep == "-inff" || literalRep == "+inff" || 
          literalRep == "nanf" || literalRep == "-inf" || 
          literalRep == "+inf" || literalRep == "nan") return PSEUDO;
        
    size_t  pos = literalRep.find('.');
        
    if (pos)
    {
        std::stringstream   extract(literalRep);
        float               f;
        double              d;

        if (extract >> d && extract.get() == EOF)
            return DOUBLE;
        else if (extract >> f && extract.get() != EOF)
        {
            std::string remains;

            extract >> remains;
            if (remains == "f")
                return FLOAT;
        }

    }

    return NONE;
}

static void
ConvertChar( const std::string& literalRep )
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

static void
ConvertInt( const std::string& literalRep )
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
ScalarConverter::convert( const std::string& literalRep )
{
   t_type               type = get_type(literalRep);
   char                 c;
   long                 i;
   float                f;
   double               d;
   bool                 impo = false;
   bool                 err = false;
   std::stringstream    extract(literalRep);

   if (type == CHAR)
   {
        c = literalRep[1];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    }
   else if (type == INT)
   {

        if (extract >> i)
        {
            if ( i > INT32_MAX || i < INT32_MIN) impo = true;
            else if (isascii(i)) c = static_cast<char>(i);
            else    c = -1;
            f = static_cast<float>(i);
            d = static_cast<double>(i);
            
        }
        else
            err = true;
   }
   else if (type == FLOAT)
   {
        if (extract >> f)
        {
            d = static_cast<double>(f);
             
        }
   }
}



ScalarConverter::~ScalarConverter( void )
{
}