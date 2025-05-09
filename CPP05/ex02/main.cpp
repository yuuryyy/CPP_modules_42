#include "Bureaucrat.hpp"


int main( void )
{
    try
    {
        Bureaucrat a("a", 1);
        a.decrement();
        std::cout << a << std::endl;

        Bureaucrat b("b", 150);
        b.increment();
        std::cout << b << std::endl;

        Bureaucrat c("c", 1);
        c.increment();
        std::cout << c << std::endl;
    }

    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "end of program" << std::endl;
    
    return 0;
}