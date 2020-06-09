#ifndef SUBBUTTON_H
#define SUBBUTTON_H

#include "point.h"
#include <QString>

//子按钮类

class SubButton
{
public:
    SubButton(int x,int y);
    SubButton(const SubButton& sb);
    SubButton();//允许空白构造
    int getX()const;
    int getY()const;
    void setX(const int x);
    void setY(const int y);
    void setImagePath(const QString imagePath);
    QString getImagePath()const;
private:
    Point _p;
    QString _imagePath;
};

#endif // SUBBUTTON_H