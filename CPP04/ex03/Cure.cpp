#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure( void ) : AMateria("cure") 
{
    std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure( const Cure &Other ) : AMateria(Other) 
{
    std::cout << "Cure copy constructor called" << std::endl;
    *this = Other;
}

Cure&
Cure::operator=( const Cure &Other ) 
{
    std::cout << "Cure assignment operator called" << std::endl;
    (void)Other;
    return *this;
}

Cure::~Cure( void ) 
{
    std::cout << "Cure destructor called" << std::endl;
}

AMateria*
Cure::clone( void ) const 
{
    std::cout << "Cure clone method called" << std::endl;
    return new Cure(*this);
}

void
Cure::use( ICharacter& target ) 
{
        std::cout << "Cure use method called" << std::endl; 
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}