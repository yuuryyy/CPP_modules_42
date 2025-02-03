#include "Fixed.hpp"

const int Fixed::fractionalBITS = 8;

Fixed::Fixed( void ) : _value(0)
{
}

Fixed::Fixed( const Fixed &Obj)
{
    _value = Obj.getRawBits();
}


Fixed &Fixed::operator=( const Fixed &Obj )
{
    if (this != &Obj)
    {
        _value = Obj.getRawBits();
    }
    return *this;
}

Fixed::Fixed( const int Number)
{

    _value = Number * (1 << fractionalBITS);
}

Fixed::Fixed( const float Number)
{
    float   result;

    result = Number * (1 << fractionalBITS);
    _value = roundf(result);

}

Fixed::~Fixed( void )
{
    _value = 0;
}

int Fixed::getRawBits( void ) const
{
    
    return _value; 
}

void Fixed::setRawBits( int const raw )
{
    
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

bool    Fixed::operator>( const Fixed &other )
{
    return this->_value > other.getRawBits();
}

bool    Fixed::operator<( const Fixed &other )
{
    return this->_value < other.getRawBits();
}

bool    Fixed::operator>=( const Fixed &other )
{
    return this->_value >= other.getRawBits();
}

bool    Fixed::operator<=( const Fixed &other )
{
    return this->_value <= other.getRawBits();
}

bool    Fixed::operator==( const Fixed &other )
{
    return this->_value == other.getRawBits();
}

bool    Fixed::operator!=( const Fixed &other )
{
    return this->_value != other.getRawBits();
}


Fixed   Fixed::operator+( const Fixed &other )
{
    Fixed Result(this->toFloat() + other.toFloat());
    return Result;
}

Fixed   Fixed::operator-( const Fixed &other )
{
    Fixed Result(this->toFloat() - other.toFloat());
    return Result;
}

Fixed   Fixed::operator*( const Fixed &other )
{
    Fixed Result(this->toFloat() * other.toFloat());
    return Result;
}

Fixed   Fixed::operator/( const Fixed &other )
{
    Fixed Result(this->toFloat() / other.toFloat());
    return Result;
}

Fixed   &Fixed::operator++( void )
{
    _value += 1;
    return *this;
}
Fixed   Fixed::operator++( int )
{
    Fixed   temp = *this;

    this->_value += 1;
    return temp;
}
Fixed   &Fixed::operator--( void )
{
    _value -= 1;
    return *this;
}
Fixed   Fixed::operator--( int )
{
    Fixed   temp = *this;

    this->_value -= 1;
    return temp;
}

Fixed   &Fixed::min(Fixed &Obj1, Fixed &Obj2)
{
    if (Obj1 < Obj2)
        return Obj1;
    return Obj2;
}

Fixed   &Fixed::min(const Fixed &Obj1, const Fixed &Obj2)
{
    if ((Fixed)Obj1 < Obj2)
        return (Fixed)Obj1;
    return(Fixed) Obj2;
}