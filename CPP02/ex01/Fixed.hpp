#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
       int            _value;
       static const int fractionalBITS;
       
    public:

        Fixed( void );
        Fixed( const Fixed &Obj );
        Fixed &operator=( const Fixed &Obj );
        ~Fixed( void );

        Fixed( const int Number );
        Fixed( const float Number );

        int getRawBits( void ) const;
        void setRawBits( int const raw );

        float toFloat( void ) const;
        int   toInt( void ) const;

};

std::ostream &operator<<(std::ostream &__out, const Fixed &obj);

#endif