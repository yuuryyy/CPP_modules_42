#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"


class PresidentialPardonForm : public Form
{
    private:
        const std::string _target;

    public:

        PresidentialPardonForm( void );
        PresidentialPardonForm( const std::string target );
        PresidentialPardonForm( const PresidentialPardonForm &src );
        PresidentialPardonForm &operator=( const PresidentialPardonForm &src );
        
        void action( void ) const;

        ~PresidentialPardonForm( void );

};

#endif