#include "Fixed.hpp"

const int Fixed::fractionalBITS = 8;

Fixed::Fixed( void ) : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &Obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = Obj;
}

Fixed &Fixed::operator=( const Fixed &Obj )
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &Obj)
    {
        _value = Obj.getRawBits();
    }
    return *this;
}

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
    _value = 0;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called " << std::endl;
    _value = raw;
}