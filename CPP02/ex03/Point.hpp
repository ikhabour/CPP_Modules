#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"



class Point
{
    private:
        Fixed const x;
        Fixed const y;
    public:
        Point();
        Point(const float n1, const float n2);
        Point(const Point& other);
        Point& operator=(const Point& other);
        ~Point();
        Fixed get_x() const ;
        Fixed get_y() const ;
};


bool bsp( Point const a, Point const b, Point const c, Point const point);


#endif