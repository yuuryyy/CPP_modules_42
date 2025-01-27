#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
       int              _value;
       static const int fractionalBITS;
    public:

        Fixed( void );
        Fixed( const Fixed &Obj );
        Fixed &operator=( const Fixed &Obj );
        ~Fixed( void );

        int getRawBits( void ) const;
        void setRawBits( int const raw );

};


#endif