#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point 
{
    private:
        Fixed const x;
        Fixed const y;

    public:
        Point( void );
        Point( const float x_, const float y_ );
        Point( const Point& Other);
        Point operator=( const Point &Other);
        ~Point( void );

        const Fixed get_X( void ) const;
        const Fixed get_Y( void ) const;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);


#endif