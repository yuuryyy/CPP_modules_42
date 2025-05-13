#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"


enum    t_form
{
    PRESIDENTIALPARDONFORM,
    ROBOTOMYREQUESTFORM,
    SHRUBBERYCREATIONFORM,
};

class Intern
{

    public:

        Intern( void );
        Intern( const Intern& other );
        Intern &operator=( const Intern &other);
        ~Intern ( void );

        AForm   *makeForm( const std::string name, const std::string target );
        
};


#endif