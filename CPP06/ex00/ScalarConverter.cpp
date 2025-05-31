#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    *this = other;
}

ScalarConverter &
ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

static bool
isInt(const std::string &literalRep)
{
    bool sign = false;

    if (literalRep[sign] == '+' || literalRep[sign] == '-')
    {
        if (literalRep.length() == 1)
            return false;
        sign = true;
    }

    for (size_t i = sign; i < literalRep.length(); i++)
        if (!isdigit(literalRep[i]))
            return false;

    return true;
}

static t_type get_type(const std::string &literalRep)
{
    if (literalRep.length() == 3 && literalRep[0] == '\'' && literalRep[2] == '\'' && (isascii(literalRep[1])))
        return CHAR;

    else if (isInt(literalRep))
        return INT;

    if (literalRep == "-inff" || literalRep == "+inff" ||
        literalRep == "nanf" || literalRep == "-inf" ||
        literalRep == "+inf" || literalRep == "nan")
        return PSEUDO;

    size_t pos = literalRep.find('.');

    if (pos)
    {
        std::stringstream extract(literalRep);
        float f;
        double d;

        if (extract >> d && extract.get() == EOF)
            return DOUBLE;
        extract.clear();
        extract.seekg(0, std::ios_base::beg);
        if (extract >> f)
        {
            std::cout << "**********" << literalRep << std::endl;
            std::string remains;
            extract >> remains;
            std::cout << "---------------------" << remains << std::endl;
            if (remains == "f")
                return FLOAT;
        }
    }

    return NONE;
}

void ScalarConverter::convert(const std::string &literalRep)
{

    t_type type = get_type(literalRep);
    char c;
    long i;
    float f;
    double d;
    bool impo = false;
    bool err = false;

    if (type == CHAR)
    {

        c = literalRep[1];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    }
    else if (type == INT)
    {
        std::stringstream extract(literalRep);
        if (extract >> i)
        {
            std::cout << i << "-----------------------------" << std::endl;
            if (i > INT_MAX || i < INT_MIN)
                impo = true;
            else if (isascii(i))
                c = static_cast<char>(i);
            else
                c = -1;
            f = static_cast<float>(i);
            d = static_cast<double>(i);
        }
        else
            err = true;
    }
    else if (type == FLOAT)
    {
        std::stringstream extract(literalRep);
        if (extract >> f)
        {
            d = static_cast<double>(f);
            if (f > INT_MAX || f < INT_MIN)
                impo = true;
            else
                i = static_cast<int>(f);
            if (!impo && isascii(i))
                c = static_cast<char>(f);
            else
                c = -1;
        }
        else
            err = true;
    }
    else if (type == DOUBLE)
    {
        std::stringstream extract(literalRep);
        if (extract >> d)
        {
            f = static_cast<float>(d);
            if (d > INT_MAX || d < INT_MIN)
                impo = true;
            else
                i = static_cast<int>(d);
            if (!impo && isascii(i))
                c = static_cast<char>(d);
            else
                c = -1;
        }
        else
            err = true;
    }
    else if (type == PSEUDO)
    {
        std::cout << "Char  : Impossible\nInt   : Impossible\n";
        if (literalRep == "-inff")
            std::cout << "Float : -inff\nDouble: -inf";
        else if (literalRep == "+inff")
            std::cout << "Float : +inff\nDouble: +inf";
        else if (literalRep == "nanf")
            std::cout << "Float : nanf\nDouble: nan";
        else if (literalRep == "-inf")
            std::cout << "Float : -inff\nDouble: -inf";
        else if (literalRep == "+inf")
            std::cout << "Float : +inff\nDouble: +inf";
        else if (literalRep == "nan")
            std::cout << "Float : nanf\nDouble: nan";
        std::cout << std::endl;
        return;
    }
    else
        err = true;
    if (!err)
    {
        size_t pos = literalRep.find_first_of('.');
        int precision = literalRep.length() - pos - 1;
        if (pos == std::string::npos)
            precision = 1;
        else if (type == FLOAT)
            precision--;
        if (impo)
            std::cout << "Char   : Impossible\nInt    : Impossible\n";
        else
        {
            std::cout << "Char   : ";
            if (c == -1)
                std::cout << "Impossible\n";
            else if (isprint(c))
                std::cout << '\'' << c << "\'\n";
            else
                std::cout << "Non displayable\n";
            std::cout << "Int    : " << i << "\n";
        }
        std::cout << std::fixed << std::setprecision(precision);
        std::cout << "Float  : " << f;
        std::cout << "f\n";
        std::cout << "Double : " << d;
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Char  : Impossible\nInt   : Impossible\n"
                  << "Float : Impossible\nDouble: Impossible\n";
    }
}

ScalarConverter::~ScalarConverter(void)
{
}

// static void
// ConvertChar( const std::string& literalRep )
// {

//     char c = literalRep[1];
//     std::cout << "Char : ";
//     if (isprint(c)) std::cout << '\'' << c << "\'" ;
//     else            std::cout << "Non displayable";
//     std::cout << std::endl;

//     std::cout << "Int : " << static_cast<int>(c) << std::endl;

//     std::cout << "Float : " << static_cast<float>(c);
//     if (static_cast<float>(c) == static_cast<int>(c))   std::cout << ".0f";
//     std::cout << std::endl;

//     std::cout << "Double : " << static_cast<double>(c) << std::endl;
//     if (static_cast<double>(c) == static_cast<int>(c))   std::cout << ".0";
//     std::cout << std::endl;
// }

// static void
// ConvertInt( const std::string& literalRep )
// {
//     int i;
//     std::istringstream   extract(literalRep);

//     extract >> i;

//     if (extract.fail() || !extract.eof())
//     {
//         std::cout << "Char: Impossible\nInt: Impossible\n"
//                   << "Float: Impossible\nDouble: Impossible\n";
//         return ;
//     }

//     char    c = static_cast<char>(i);

//     std::cout << "Char : ";
//     if (isprint(c) && isascii(i))
//         std::cout << '\'' << c << "\'" ;
//     else if (!isascii(i))
//         std::cout << "Impossible";

//     else
//         std::cout << "Non displayable";
//     std::cout << std::endl;

//     std::cout << "Int : " << i << std::endl;

//     std::cout << "Float : " << static_cast<float>(i);
//     if (static_cast<float>(i) == static_cast<int>(i))   std::cout << ".0f";
//     std::cout << std::endl;

//     std::cout << "Double : " << static_cast<double>(i) << std::endl;
//     if (static_cast<double>(i) == static_cast<int>(i))   std::cout << ".0";
//     std::cout << std::endl;
// }
