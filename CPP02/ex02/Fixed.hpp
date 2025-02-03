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

        static Fixed& min( Fixed &Obj1, Fixed &Obj2);
        static Fixed& min( const Fixed &Obj1, const Fixed &Obj2);

        static Fixed& max( Fixed &Obj1, Fixed &Obj2);
        static Fixed& max( const Fixed &Obj1, const Fixed &Obj2);

        Fixed( void );
        Fixed( const Fixed &Obj );
        Fixed &operator=( const Fixed &Obj );
        ~Fixed( void );

        bool operator>( const Fixed &other) ;
        bool operator<( const Fixed &other );
        bool operator>=( const Fixed &other );
        bool operator<=( const Fixed &other );
        bool operator==( const Fixed &other );
        bool operator!=( const Fixed &other );

        Fixed operator+( const Fixed &other );
        Fixed operator-( const Fixed &other );
        Fixed operator*( const Fixed &other );
        Fixed operator/( const Fixed &other );

        Fixed &operator++( void );
        Fixed operator++( int );
        Fixed &operator--( void );
        Fixed operator--( int );

        Fixed( const int Number );
        Fixed( const float Number );

        int getRawBits( void ) const;
        void setRawBits( int const raw );

        float toFloat( void ) const;
        int   toInt( void ) const;

};

std::ostream &operator<<(std::ostream &__out, const Fixed &obj);

#endif