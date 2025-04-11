#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice") {
    std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice( const Ice &Other ) : AMateria(Other) {
    std::cout << "Ice copy constructor called" << std::endl;
    *this = Other;
}

Ice&
Ice::operator=( const Ice &Other ) {
    std::cout << "Ice assignment operator called" << std::endl;
    if (this != &Other) {
        AMateria::operator=(Other);
    }
    return *this;
}

Ice::~Ice( void ) {
    std::cout << "Ice destructor called" << std::endl;
}

AMateria*
Ice::clone( void ) const {
    std::cout << "Ice clone method called" << std::endl;
    return new Ice(*this);
}