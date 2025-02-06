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

        static const Fixed& min( const Fixed &Obj1, const Fixed &Obj2);
        static Fixed& min( Fixed &Obj1, Fixed &Obj2);

        static const Fixed& max( const Fixed &Obj1, const Fixed &Obj2);
        static Fixed& max( Fixed &Obj1, Fixed &Obj2);

        Fixed &operator=( const Fixed &Obj );
        Fixed( const float Number );
        Fixed( const Fixed &Obj );
        Fixed( const int Number );
        ~Fixed( void );
        Fixed( void );

        bool operator>( const Fixed &other) const ;
        bool operator<( const Fixed &other ) const;
        bool operator>=( const Fixed &other ) const;
        bool operator<=( const Fixed &other ) const;
        bool operator==( const Fixed &other ) const;
        bool operator!=( const Fixed &other ) const;

        Fixed operator+( const Fixed &other ) const;
        Fixed operator-( const Fixed &other ) const;
        Fixed operator*( const Fixed &other ) const;
        Fixed operator/( const Fixed &other ) const;

        Fixed &operator++( void );
        Fixed operator++( int );
        Fixed &operator--( void );
        Fixed operator--( int );


        int getRawBits( void ) const;
        void setRawBits( int const raw );

        float toFloat( void ) const;
        int   toInt( void ) const;

};

std::ostream &operator<<(std::ostream &__out, const Fixed &obj);

#endif