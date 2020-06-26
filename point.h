#ifndef POINT_H
#define POINT_H


class Point
{
public:
    Point(const int x,const int y);
    Point(const Point &p);
    int getX()const;
    int getY()const;
    void setX(const int x);
    void setY(const int y);

private:
    int _x;
    int _y;
};

double getLength(const Point&p1,const Point&p2);//计算两点距离

#endif // POINT_H