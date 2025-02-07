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

Fixed::Fixed( const int Number)
{
    std::cout << "Int constructor called" << std::endl;
    _value = Number * (1 << fractionalBITS);
}

Fixed::Fixed( const float Number)
{
    float   result;

    result = Number * (1 << fractionalBITS);
    _value = roundf(result);

    std::cout << "Float constructor called" << std::endl;
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

float   Fixed::toFloat( void ) const
{
    float   result = (float)_value / (1 << fractionalBITS);

    return result;
}

int     Fixed::toInt( void ) const
{
    return _value / (1 << fractionalBITS);
}

std::ostream &operator<<(std::ostream &__out, const Fixed &obj)
{
    __out << obj.toFloat();
    return __out;
}