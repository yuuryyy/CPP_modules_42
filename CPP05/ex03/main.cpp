#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main( void )
{
    srand(time(0));

    Intern      randomIntern;
    std::string sep(70,'*');
    AForm       *form;
    
    std::string testForms[] = {
                            "presidential pardon",
                            "robotomy request",
                            "shrubbery creation",
                            "zaza form"
                            };

    try
    {
        Bureaucrat randomBureaucrat("Bureaucraaaack", 1);
        

        for(int i = 0; i < 4; i++)
        {
            form = randomIntern.makeForm(testForms[i], "target");
            if (form)
            {
                randomBureaucrat.signForm(*form);
                randomBureaucrat.executeForm(*form);
                delete form;
            }
            std::cout << sep << std::endl;
        }

    }
    
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << "end of program" << std::endl;
    
    return 0;
}