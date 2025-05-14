#include "Intern.hpp"

Intern::Intern( void )
{
}

Intern::Intern( const Intern &other )
{
    *this = other;
}

Intern
&Intern::operator=( const Intern &other)
{
    (void) other;
    return *this;
}

AForm*
Intern::makeForm( const std::string name, const std::string target )
{
    int     i = 0;
    AForm   *form;
    const std::string forms[] = {
                            "presidential pardon",
                            "robotomy request",
                            "shrubbery creation"
                            };

    while (forms[i] != name && i < 3)
        i++;

    switch (i)
    {
        case PRESIDENTIALPARDONFORM:
            form = new PresidentialPardonForm(target);
            break;
        case ROBOTOMYREQUESTFORM:
            form = new RobotomyRequestForm(target);
            break;
        case SHRUBBERYCREATIONFORM:
            form = new ShrubberyCreationForm(target);
            break;
        default:
            form = NULL;
            break;
    }

    if (!form)
        std::cout << "ERROR : WHAT IS " << name << " ?!";
    else
        std::cout << "Intern creates " << name << " form";

    std::cout << std::endl;

    return form;
}

Intern::~Intern( void)
{
}

