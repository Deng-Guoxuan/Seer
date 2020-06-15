#include "pirates.h"
#include "blackbullet.h"
#include "brownbullet.h"

const int PIX=64;

Pirates::Pirates(Point **path, int pathLength, Point &p):
     _p(p.getX(),p.getY())
{
    for(int i=0;i<pathLength;i++){
        this->_turningPoints.push_back(path[i]);//将转折点插入动态数组中
    }
}

int Pirates::getFullLife()const{
    return this->_fullLife;
}

void Pirates::setSplashed(const bool tf){
    this->_isSplashed=tf;
}

bool Pirates::getSplashed()const{
    return this->_isSplashed;
}

//取得速度
int Pirates::getSpeed()const{
    return this->_speed;
}

int Pirates::getFullSpeed()const{
    return this->_fullSpeed;
}

void Pirates::setWaved(const bool tf){
    this->_isWaved=tf;
}

bool Pirates::getWaved()const{
    return this->_isWaved;
}

//左上角x坐标
int Pirates::getX()const{
    return this->_p.getX();
}

//左上角y坐标
int Pirates::getY()const{
    return this->_p.getY();
}

//取得血量
int Pirates::getLife()const{
    return this->_life;
}

//设置血量
void Pirates::setLife(const int life){
    this->_life=life;
}

//取得图片路径
QString Pirates::getImagePath()const{
    return this->_imagePath;
}

//获得海盗类型
int Pirates::getID()const{
    return this->_id;
}

bool Pirates::isEnd(){
    if(this->_turningPoints.empty()){
        return true;                      //到达了终点
    }
    else return false;
}

void Pirates::setShocked(const bool tf){
    this->_shocked=tf;
}

bool Pirates::getShocked()const{
    return this->_shocked;
}

//海盗按设定路径点移动
void Pirates::pirateMove()
{
    if(this->_turningPoints.empty()){
        return;                      //到达了终点
    }

    if(this->_isWaved){
        this->_norSpdBlank=0;       //开始计算减速时间
        this->_isWaved=false;
    }

    if(this->_shocked){
        this->_norSpdBlank=0;
        this->_shocked=false;
    }

    if(this->_norSpdBlank==50){           //到时间恢复原速度
        this->_speed=this->_fullSpeed;
    }
    else{
        this->_norSpdBlank++;
    }

    //如果第一个路径点的y小于海盗原本的路径点，则海盗向下走
    if ((this->_turningPoints.at(0)->getY()) > (this->_p.getY())+this->getSpeed()/2) //向下
    {
        this->_p.setY(this->getY()+this->_speed);
        return;
    }

    if ((this->_turningPoints.at(0)->getX()) < (this->_p.getX())-this->getSpeed()/2) //向左
    {
        this->_p.setX(this->getX()-this->_speed);
        return;
    }

    if ((this->_turningPoints.at(0)->getX()) > (this->_p.getX())+this->getSpeed()/2) //向右
    {
        this->_p.setX(this->getX()+this->_speed);
        return;
    }

    if ((this->_turningPoints.at(0)->getY()) < (this->_p.getY())-this->getSpeed()/2) //向上
    {
        this->_p.setY(this->getY()-this->_speed);
        return;
    }

    //如果怪物的坐标和路径点坐标几乎重合，则删除这个路径点
    if (abs((this->_turningPoints.at(0)->getY())-(this->getY()))<=this->getSpeed()/2 && abs(this->_turningPoints.at(0)->getX()-this->getX())<=this->getSpeed()/2)
    {
        delete this->_turningPoints.begin();                            //释放坐标点内存
        this->_turningPoints.erase(this->_turningPoints.begin());       //从数组中删除
    }

    return;
}

void Pirates::setSpeed(const int speed){
    this->_speed=speed;
}

int Pirates::getReward()const{
    return this->_reward;
}

int Pirates::getRange()const{
    return this->_range;
}

QString Pirates::getRangeColor()const{
    return this->_rangeColor;
}


int Pirates::getFireBlank()const{
    return this->_fireBlank;
}//攻击间隔

QVector<Bullet*>& Pirates::getBulletVector(){
    return this->_bulletVector;
}

void Pirates::setCountBlank(const int t){
    this->_countBlank=t;
}

//输入一个精灵的中心点
void Pirates::addBullet(Point&targetP){
    this->_countBlank++;

    if(this->_countBlank<this->getFireBlank()){ //没有达到时间间隔,不用新建子弹
        return;
    }
    else{
        Point p1(this->getX()+PIX/2,this->getY()+PIX/2);//海盗的中心点
        switch (this->_id){
        case 1:                   //pirate1:黑灰子弹
        {
            this->_bulletVector.push_back(new BlackBullet(p1,targetP));
            break;
        }
        case 2:                   //pirate2:黑灰子弹
        {
            this->_bulletVector.push_back(new BlackBullet(p1,targetP));
            break;
        }
        case 3:
        {
            this->_bulletVector.push_back(new BrownBullet(p1,targetP));
            break;
        }
        default:
            break;
        }
        this->_countBlank=0;//归零
    }
}

void Pirates::fireBullets(){
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

void Pirates::eraseBullet(Bullet **bullet){
    this->_bulletVector.erase(bullet);
}
