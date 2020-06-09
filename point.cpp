#include "point.h"
#include <cmath>

Point::Point(const int x, const int y):_x(x),_y(y){}

Point::Point(const Point &p):_x(p.getX()),_y(p.getY()){}

double getLength(const Point &p1, const Point &p2){
    double l=sqrt((p1.getX()-p2.getX())*(p1.getX()-p2.getX())+(p1.getY()-p2.getY())*(p1.getY()-p2.getY()));
    return l;
}

int Point::getX()const{
    return this->_x;
}

int Point::getY()const{
    return this->_y;
}

void Point::setX(const int x){
    this->_x=x;
}

void Point::setY(const int y){
    this->_y=y;
}