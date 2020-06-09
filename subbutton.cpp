#include "subbutton.h"

SubButton::SubButton(int x, int y):_p(x,y){}

SubButton::SubButton(const SubButton &sb):_p(sb.getX(),sb.getY()){}

SubButton::SubButton():_p(0,0){}

int SubButton::getX()const{
    return this->_p.getX();
}

int SubButton::getY()const{
    return this->_p.getY();
}

void SubButton::setX(const int x){
    this->_p.setX(x);
}

void SubButton::setY(const int y){
    this->_p.setY(y);
}

void SubButton::setImagePath(const QString imagePath){
    this->_imagePath=imagePath;
}

QString SubButton::getImagePath()const{
    return this->_imagePath;
}
