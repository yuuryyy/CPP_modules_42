#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("PPF", 25, 5), _target("PPF")
{
    // std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const std::string target ) : AForm(target, 25, 5), _target(target)
{
    // std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &src ) : AForm(src), _target(src._target)
{
    // std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm
&PresidentialPardonForm::operator=( const PresidentialPardonForm &src )
{
    // std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
    (void)src;
    return *this;
}

void
PresidentialPardonForm::action( void ) const
{
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}


PresidentialPardonForm::~PresidentialPardonForm( void )
{
    // std::cout << "PresidentialPardonForm destructor called" << std::endl;
}