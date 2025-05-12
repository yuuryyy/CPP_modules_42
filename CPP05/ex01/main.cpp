#include "Bureaucrat.hpp"

int main( void )
{
    try
    {
        Bureaucrat a("SAGH", 1);
        a.decrement();
        std::cout << a << std::endl;

        Bureaucrat b("ZAZA", 150);
        b.increment();
        std::cout << b << std::endl;

        Form   form("FOORMMM", 1, 1);
        
        a.increment();
        form.beSigned(a);
        std::cout << form << std::endl;

        form.beSigned(a);
        form.beSigned(b);

    }

    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "end of program" << std::endl;
    
    return 0;
}