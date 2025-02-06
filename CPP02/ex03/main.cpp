#include "Point.hpp"

int main( void ) {

    Point a(0, 0); 
    Point b(5, 0);
    Point c(0, 5);
    Point p(1, 1);

    std::cout << (bsp(a, b, c, p) ? "the point is inside the triangle" : "the point isn't inside the triangle") << std::endl;

    Point p2(a);

    p = p2;

    std::cout << (bsp(a, b, c, p) ? "the point is inside the triangle" : "the point isn't inside the triangle") << std::endl;
    return 0;
}
