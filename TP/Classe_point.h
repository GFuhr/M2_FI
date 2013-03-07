#ifndef __CLASS_POINT
#define __CLASS_POINT

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

//classe point
class Point {
    double  _x ;
    double  _y ;

public:
    Point(void) ;
    Point(const double val_x, const double val_y);
    Point(const Point &p);
    ~Point(void);

    void setX(const double val);
    void setY(const double val);
    double  getX(void) const ;
    double  getY(void) const ;

    double  distance(const Point &p) const;

};

#endif
