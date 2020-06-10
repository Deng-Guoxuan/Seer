#include "pirates.h"

Pirates::Pirates(Point **path, int pathLength, Point &p, int id):
    _p(p.getX(),p.getY()),_id(id)
{
    for(int i=0;i<pathLength;i++){
        this->_turningPoints.push_back(path[i]);//将转折点插入动态数组中
    }

    //根据id类型对海盗进行初始化
    switch (id) {
    case 1:                        //pirate1
        this->_life=100;
        this->_speed=6;
        this->_imagePath=":/Image/pictures/pirate1.png";
        this->_reward=20;
        break;
    case 2:
        this->_life=120;
        this->_speed=12;
        this->_imagePath=":/Image/pictures/pirate2.png";
        this->_reward=40;
    default:
        break;
    }
}

//取得速度
int Pirates::getSpeed()const{
    return this->_speed;
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
void Pirates::setLife(int life){
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

//海盗按设定路径点移动
bool Pirates::pirateMove()
{
    if(this->_turningPoints.empty()){
        return true;                      //到达了终点
    }

    //如果第一个路径点的y小于海盗原本的路径点，则海盗向下走
    if ((this->_turningPoints.at(0)->getY()) > (this->_p.getY())+this->getSpeed()/2) //向下
    {
        this->_p.setY(this->getY()+this->_speed);
        return false;
    }

    if ((this->_turningPoints.at(0)->getX()) < (this->_p.getX())-this->getSpeed()/2) //向左
    {
        this->_p.setX(this->getX()-this->_speed);
        return false;
    }

    if ((this->_turningPoints.at(0)->getX()) > (this->_p.getX())+this->getSpeed()/2) //向右
    {
        this->_p.setX(this->getX()+this->_speed);
        return false;
    }

    if ((this->_turningPoints.at(0)->getY()) < (this->_p.getY())-this->getSpeed()/2) //向上
    {
        this->_p.setY(this->getY()-this->_speed);
        return false;
    }

    //如果怪物的坐标和路径点坐标几乎重合，则删除这个路径点
    if (abs((this->_turningPoints.at(0)->getY())-(this->getY()))<=this->getSpeed()/2 && abs(this->_turningPoints.at(0)->getX()-this->getX())<=this->getSpeed()/2)
    {
        delete this->_turningPoints.begin();                            //释放坐标点内存
        this->_turningPoints.erase(this->_turningPoints.begin());       //从数组中删除
    }

    return false;
}

int Pirates::getReward()const{
    return this->_reward;
}
