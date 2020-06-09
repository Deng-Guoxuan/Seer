#include "spirits.h"
#include "greenbullet.h"

const int PIX=64;//一格的像素

Spirits::Spirits(int x, int y):_p(x,y){}


int Spirits::getX()const{
    return this->_p.getX();
}//左上角x坐标

int Spirits::getY()const{
    return this->_p.getY();
}//左上角y坐标

int Spirits::getRange()const{
    return this->_range;
}//攻击范围

QString Spirits::getImagePath()const{
    return this->_imagePath;
}//获得图片路径

QString Spirits::getRangeColor()const{
    return this->_rangeColor;
}//获得攻击范围的颜色

Pirates* Spirits::getTarget()const{
    return this->_target;
}

void Spirits::setTarget(Pirates *target){
    this->_target=target;
}

int Spirits::getFireBlank()const{
    return this->_fireBlank;
}//攻击间隔

QVector<Bullet*>& Spirits::getBulletVector(){
    return this->_bulletVector;
}

void Spirits::addBullet(){
    this->_countBlank++;

    if(this->_countBlank<this->getFireBlank()||!this->_target){ //没有达到时间间隔或没有目标,不用新建子弹
        return;
    }
    else{
        switch (this->_type){
        case 1:                   //萌布布种子:绿子弹
        {
            Point p1(this->getX()+PIX/2,this->getY()+PIX/2);//精灵的中心点
            Point p2(this->_target->getX()+PIX/2,this->_target->getY()+PIX/2);//目标的中心点
            this->_bulletVector.push_back(new GreenBullet(p1,p2));
            break;
        }
        default:
            break;
        }
        this->_countBlank=0;//归零
    }
}

void Spirits::fireBullets(){
    //子弹移动
    for(auto bullet : this->_bulletVector)
    {
        bullet->bulletMove();
    }

    //遍历删除越界子弹
    for(auto bullet = this->_bulletVector.begin(); bullet != this->_bulletVector.end(); bullet++)
        if((*bullet)->getX()<0 || (*bullet)->getX()>18*PIX || (*bullet)->getY()>10*PIX || (*bullet)->getY()<0)
        {
            this->_bulletVector.erase(bullet);
            break;
        }
}

void Spirits::eraseBullet(Bullet **i){
    for(auto bullet=this->_bulletVector.begin();bullet<this->_bulletVector.end();bullet++){
        if(bullet==i){
            this->_bulletVector.erase(bullet);
        }
        else continue;
    }
}