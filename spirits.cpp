#include "spirits.h"
#include "greenbullet.h"
#include "redbullet.h"
#include "bluebullet.h"
#include "lightingbullet.h"
#include "knifebullet.h"
#include "shiningbullet.h"
#include "flowerbullet.h"
#include "firebullet.h"
#include "waterbullet.h"
#include "thunderbullet.h"
#include "swordbullet.h"
#include "sunbullet.h"

const int PIX=64;//一格的像素

Point directions[]={Point(0,0),Point(0,2*PIX),Point(0,4*PIX),Point(0,6*PIX),Point(0,8*PIX),Point(0,10*PIX),
                    Point(18*PIX,0),Point(18*PIX,2*PIX),Point(18*PIX,4*PIX),Point(18*PIX,6*PIX),Point(18*PIX,8*PIX),Point(10*PIX,18*PIX),
                    Point(0,0),Point(2*PIX,0),Point(4*PIX,0),Point(6*PIX,0),Point(8*PIX,0),Point(10*PIX,0),Point(12*PIX,0),Point(14*PIX,0),Point(16*PIX,0),Point(18*PIX,0),
                    Point(0,10*PIX),Point(2*PIX,10*PIX),Point(4*PIX,10*PIX),Point(6*PIX,10*PIX),Point(8*PIX,10*PIX),Point(10*PIX,10*PIX),Point(12*PIX,10*PIX),Point(14*PIX,10*PIX),Point(16*PIX,10*PIX),Point(18*PIX,10*PIX)};
const int dirL=sizeof(directions)/sizeof(Point);

Spirits::Spirits(int x, int y):_p(x,y){}

int Spirits::getType()const{
    return this->_type;
}

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

int Spirits::getCountLifeBlank()const{
    return this->_countLifeBlank;
}

int Spirits::getAddLifeBlank()const{
    return this->_addLifeBlank;
}

int Spirits::getCountFireBlank()const{
    return this->_countBlank;
}

void Spirits::setCountFireBlank(const int num){
    this->_countBlank=num;
}

void Spirits::addLife(QVector<Spirits *> &spiritsVector){
    this->_countLifeBlank++;

    if(this->_countLifeBlank<this->_addLifeBlank){ //没到时间不能补血
        return;
    }
    else if(this->_type==1||this->_type==7){//这是萌布布种子或其进化形态蒙娜丽莎,有补血技能
        int addRange=0;
        if(this->_type==1){
            addRange=120;
        }
        else{
            addRange=200;
        }
        for(auto spirit:spiritsVector){
            Point p1(this->getX()+PIX/2,this->getY()+PIX/2);
            Point p2(spirit->getX()+PIX/2,spirit->getY()+PIX/2);
            if(getLength(p1,p2)<=addRange){                    //在范围内
                if(spirit->getLife()+this->_addLife > spirit->getFullLife()){
                    spirit->setLife(spirit->getFullLife());                       //加血只能加到上限
                }
                else{
                    spirit->setLife(spirit->getLife()+this->_addLife);//加血
                }
            }
        }
    }
    else{               //只是普通精灵,只能给自己加血
        if(this->getLife()+this->_addLife > this->getFullLife()){
            this->setLife(this->getFullLife());                       //加血只能加到上限
        }
        else{
            this->setLife(this->getLife()+this->_addLife);//加血
        }
    }
    this->_countLifeBlank=0;//归零
}

void Spirits::addBullet(){
    this->_countBlank++;

    if(this->_countBlank<this->getFireBlank()){ //没有达到时间间隔
        return;
    }
    else if(this->_type!=6&&this->_type!=12&&!this->_target){//非谱尼且没有目标,不用新建子弹
        return;
    }
    else{
        Point p1(this->getX()+PIX/2,this->getY()+PIX/2);//精灵的中心点
        if(this->_type!=6&&this->_type!=12){
            Point p2(this->_target->getX()+PIX/2,this->_target->getY()+PIX/2);//目标的中心点
            switch (this->_type){
            case 1://萌布布种子:绿子弹
            {
                this->_bulletVector.push_back(new GreenBullet(p1,p2));
                break;
            }
            case 2://萌火猴
            {
                this->_bulletVector.push_back(new RedBullet(p1,p2));
                break;
            }
            case 3://萌伊尤
            {
                this->_bulletVector.push_back(new BlueBullet(p1,p2));
                break;
            }
            case 4://雷伊
            {
                this->_bulletVector.push_back(new LightingBullet(p1,p2));
                break;
            }
            case 5://英卡洛斯
            {
                this->_bulletVector.push_back(new KnifeBullet(p1,p2));
                break;
            }
            case 7://蒙娜丽莎
            {
                this->_bulletVector.push_back(new FlowerBullet(p1,p2));
                break;
            }
            case 8://炽焰金刚
            {
                this->_bulletVector.push_back(new FireBullet(p1,p2));
                break;
            }
            case 9://利爪鲁斯王
            {
                this->_bulletVector.push_back(new WaterBullet(p1,p2));
                break;
            }
            case 10://S_雷伊
            {
                this->_bulletVector.push_back(new ThunderBullet(p1,p2));
                break;
            }
            case 11://S_英卡洛斯
            {
                this->_bulletVector.push_back(new SwordBullet(p1,p2));
                break;
            }
            default:break;
            }
        }
        else{                                  //谱尼或S_谱尼增加子弹
            if(this->_type==6){
                for(int i=0;i<dirL;i++){
                    this->_bulletVector.push_back(new ShiningBullet(p1,directions[i]));
                }
            }
            else{
                for(int i=0;i<dirL;i++){
                    this->_bulletVector.push_back(new SunBullet(p1,directions[i]));
                }
            }
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

int Spirits::getFullLife()const{
    return this->_fullLife;
}

void Spirits::eraseBullet(Bullet **bullet){
    this->_bulletVector.erase(bullet);
}

int Spirits::getLife()const{
    return this->_life;
}

void Spirits::setLife(const int life){
    this->_life=life;
}