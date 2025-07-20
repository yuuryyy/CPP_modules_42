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

static t_type get_type(const std::string &literalRep)
{
    std::stringstream   extract(literalRep);
    int                 i;

    if (literalRep == "-inff" || literalRep == "+inff" ||
        literalRep == "nanf" || literalRep == "-inf" ||
        literalRep == "+inf" || literalRep == "nan")
        return PSEUDO;

    else if (literalRep.length() == 1 && (isascii(literalRep[0])))
        return CHAR;

    else if(extract >> i && extract.get() == EOF)
        return INT;

    size_t pos = literalRep.find('.');
        
    if (pos != std::string::npos)
    {
        std::cout << "Original input: '" << literalRep << "'" << std::endl;
        
        extract.clear();
        extract.seekg(0, std::ios_base::beg);
        double d;
        bool double_success = extract >> d;
        bool double_eof = (extract.get() == EOF);
        
        std::cout << "Double extraction: " << (double_success ? "SUCCESS" : "FAILED") << std::endl;
        std::cout << "Double EOF check: " << (double_eof ? "TRUE" : "FALSE") << std::endl;
        
        if (double_success && double_eof)
            return DOUBLE;
        
        if (literalRep.back() == 'f')
        {
            std::cout << "heeeere\n";
            std::string without_suffix = literalRep.substr(0, literalRep.length() - 1);
            std::stringstream clean_stream(without_suffix);
            std::cout << "without_suffix: '" << without_suffix << "'" << std::endl;
            
            double f;
            bool float_success = clean_stream >> f;
            bool float_eof = (clean_stream.get() == EOF);
            
            std::cout << "Float extraction: " << (float_success ? "SUCCESS" : "FAILED") << std::endl;
            std::cout << "Float EOF check: " << (float_eof ? "TRUE" : "FALSE") << std::endl;
            std::cout << "Extracted value: " << f << std::endl;
            
            if (float_success && float_eof) {
                std::cout << "Returning FLOAT" << std::endl;
                return FLOAT;
            }
        }
    }
    std::cout << "Returning NONE" << std::endl;
        // extract.clear();
        // extract.seekg(0, std::ios_base::beg);
        // double d;

        // if (extract >> d && extract.get() == EOF)
        //     return DOUBLE;

        // extract.clear();
        // extract.seekg(0, std::ios_base::beg);
        

        // if (literalRep.back() == 'f')
        // {
        //     std::cout<< "heeeere\n";
        //     std::string without_suffix = literalRep.substr(0, literalRep.length() - 1);
        //     std::stringstream clean_stream(without_suffix);
        //     std::cout << without_suffix << std::endl;
        //     double f;
        //     if (clean_stream >> f && clean_stream.get() == EOF) {
        //         return FLOAT;
        // }

        // double f;
        // if (extract >> f)
        // {
        //     std::cout << "floaaaaat\n";
        //     std::string remains;
        //     extract >> remains;
        //     if (remains == "f")
        //         return FLOAT;
        // }
    return NONE;
}

void ScalarConverter::convert(const std::string &literalRep)
{

    t_type  type = get_type(literalRep);
    char    c;
    int     i;
    float   f;
    double  d;
    bool    impo = false;
    bool    err = false;

    if (type == CHAR)
    {

        c = literalRep[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    }
    else if (type == INT)
    {
        std::stringstream extract(literalRep);
        if (extract >> i)
        {
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
        literalRep = literalRep.substr(0, literalRep.length() - 1);
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
        std::cout << "Char      : Impossible\nInt       : Impossible\n";
        if (literalRep == "-inff" || literalRep == "+inff" || literalRep == "nanf")
            std::cout << "Float     : " << literalRep << "\nDouble    : " << literalRep.substr(0, literalRep.length() - 1);
        else
            std::cout << "Float     : " << literalRep << "f\nDouble    : " << literalRep;
        std::cout << std::endl;
        return;
    }
    else
        err = true;
    if (!err)
    {
        size_t pos = literalRep.find_first_of('.');
        int precision = literalRep.length() - pos - 1;
        if (pos == std::string::npos || !precision)
            precision = 1;
        else if (type == FLOAT && precision > 1)
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
        std::cout << "Float  : " << static_cast<float>(d);
        std::cout << "f\n";
        std::cout << "Double : " << d;
    }
    else
    {
        std::cout << "Error: please enter the valid data types (char, int, float, double)!!";
    }
    std::cout << std::endl;
}

ScalarConverter::~ScalarConverter(void)
{
}
