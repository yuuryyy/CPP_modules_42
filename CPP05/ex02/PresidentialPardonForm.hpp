#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"


class PresidentialPardonForm : public Form
{
    public:
        PresidentialPardonForm( void );
        PresidentialPardonForm( const std::string target );
        PresidentialPardonForm( const PresidentialPardonForm &src );
        PresidentialPardonForm &operator=( const PresidentialPardonForm &src );
        ~PresidentialPardonForm( void );

        void execute( Bureaucrat const & executor ) const;



    }




#endif