#include "Point.hpp"


Fixed   calculate_area(Point const a, Point const b, Point const c)
{
    Fixed area = a.get_x() * (b.get_y() - c.get_y()) + b.get_x() * (c.get_y() - a.get_y()) + c.get_x() * (a.get_y() - b.get_y());
    return (std::abs(area.toFloat()) / 2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed triangle_ABC = calculate_area(a, b, c);

    Fixed subtriangle_APB = calculate_area(a, point, b);
    Fixed subtriangle_APC = calculate_area(a, point, c);
    Fixed subtriangle_BCP = calculate_area(b, c, point);

    Fixed sum_areas = subtriangle_APB + subtriangle_APC + subtriangle_BCP;
    if (sum_areas == triangle_ABC)
        return true;
    return false; 
}