#include "Point.hpp"

Point::Point( void ) : x(0), y(0){}

Point::Point( const float x_, const float y_) : x(x_), y(y_){}

Point::Point( const Point& Other ) : x(Other.get_X()), y(Other.get_Y()){}

Point  Point::operator=( const Point& Other)
{
    if (this != &Other)
    {
        *((Fixed *)(&x)) = Other.get_X();
        *((Fixed *)(&y)) = Other.get_Y();
    }

    return *this;
}

Point::~Point( void ){}

const Fixed Point::get_X( void ) const
{
    return this->x;
}

const Fixed Point::get_Y( void ) const
{
    return this->y;
}
