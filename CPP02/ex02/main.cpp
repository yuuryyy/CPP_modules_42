#include "Fixed.hpp"


int main( void ) 
{
    Fixed a;
    Fixed const b( Fixed( 10 ) / Fixed( 3 ) );



    if (a != b)
        std::cout << "khadamaaaa\n";
    a = b;
    if (a == b)
        std::cout << "khadamaaaa\n";
    std::cout << a << std::endl;
    // std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    // std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b.toInt() << std::endl;
    // std::cout << Fixed::max( a, b ) << std::endl;


    return 0;
}
