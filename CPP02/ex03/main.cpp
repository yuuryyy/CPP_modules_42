#include "Point.hpp"


int main( void ) {

    Point a(0, 0); 
    Point b(5, 0);
    Point c(0, 5);
    Point p(1, 1);


    std::cout << "Is point inside triangle? " << (bsp(a, b, c, p) ? "Yes" : "No") << std::endl;

    return 0;
}
