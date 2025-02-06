#include "Point.hpp"


static Fixed Abs( Fixed Fpoint)
{
    if (Fpoint < 0)
        return Fpoint * -1;
    return Fpoint;
}

static Fixed area( Point const &a, Point const &b, Point const &c )
{
    return Abs(a.get_X() * (b.get_Y() - c.get_Y()) +
               b.get_X() * (c.get_Y() - a.get_Y()) +
               c.get_X() * (a.get_Y() - b.get_Y())) / 2;
}


bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed   totalAREA = area(a, b, c);
    Fixed   area1     = area(a, b, point);
    Fixed   area2     = area(a, point, c);
    Fixed   area3     = area(point, b, c);

    // if (point == a || point == b)
    return (area1 > 0 && area2 > 0 && area3 > 0
            && ((area1 + area2 + area3) == totalAREA));
}
