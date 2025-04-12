# include "AMateria.hpp"


AMateria::AMateria( void ) : _type("default") {
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria( const AMateria &Other ) {
    std::cout << "AMateria copy constructor called" << std::endl;
    *this = Other;
}

AMateria::AMateria( const std::string &type ) : _type(type) {
    std::cout << "AMateria " << type << " constructor called" << std::endl;
}

AMateria&
AMateria::operator=( const AMateria &Other ) {
    std::cout << "AMateria assignment operator called" << std::endl;
    if (this != &Other) {
        this->_type = Other._type;
    }
    return *this;
}

AMateria::~AMateria( void ) {
    std::cout << "AMateria destructor called" << std::endl;
}

const std::string&
AMateria::getType( void ) const {
    return this->_type;
}

void
AMateria::use( ICharacter& target ) {
    std::cout << "AMateria use method called" << std::endl;
    std::cout << this->getType() <<" Materia used by " << target.getName() << std::endl;
}

// TODO: implement the use method