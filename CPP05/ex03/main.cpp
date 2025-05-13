#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main( void )
{
    try
    {
        Bureaucrat a("a", 1);
        AForm        *ppf = new PresidentialPardonForm("PPF");
        AForm        *scf = new ShrubberyCreationForm("SCF");
        AForm        *rrf = new RobotomyRequestForm("RRF");

        Bureaucrat b("b", 150);
        a.signForm(*ppf);
        a.executeForm(*ppf);

        a.signForm(*scf);
        a.executeForm(*scf);

        a.signForm(*rrf);
        a.executeForm(*rrf);

        b.signForm(*rrf);
    }

    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "end of program" << std::endl;
    
    return 0;
}