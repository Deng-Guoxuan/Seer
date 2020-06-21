#include "envovlebox.h"


const int PIX=64;

EnvovleBox::EnvovleBox(QString imagePath):
    _p(0,0),_imagePath(imagePath){}

//选中防御塔
void EnvovleBox::clickOne(int x, int y, int id)
{
    this->_type=id;//要升级的精灵类型

    //确定选择框的位置（左上角）
    this->_p.setX(x);
    this->_p.setY(y-64);

    //确定子按钮的位置
    switch (id) {
    case 1://萌布布种子
    {
        this->_subButtons[0].setX(this->getX());
        this->_subButtons[0].setY(this->getY());
        this->_subButtons[0].setImagePath(":/Image/pictures/MengNaLiSha.png");//进化版：蒙娜丽莎
        break;
    }
    case 2://萌火猴
    {
        this->_subButtons[0].setX(this->getX());
        this->_subButtons[0].setY(this->getY());
        this->_subButtons[0].setImagePath(":/Image/pictures/ChiYanJinGang.png");//进化版：炽焰金刚
        break;
    }
    case 3://萌伊尤
    {
        this->_subButtons[0].setX(this->getX());
        this->_subButtons[0].setY(this->getY());
        this->_subButtons[0].setImagePath(":/Image/pictures/LiZhuaLuSiWang.png");//进化版：利爪鲁斯王
        break;
    }
    case 4://雷伊
    {
        this->_subButtons[0].setX(this->getX());
        this->_subButtons[0].setY(this->getY());
        this->_subButtons[0].setImagePath(":/Image/pictures/S_LeiYi.png");//进化版：S雷伊
        break;
    }
    case 5://英卡洛斯
    {
        this->_subButtons[0].setX(this->getX());
        this->_subButtons[0].setY(this->getY());
        this->_subButtons[0].setImagePath(":/Image/pictures/S_YingKaLuoSi.png");//进化版：S英卡洛斯
        break;
    }
    case 6://谱尼
    {
        this->_subButtons[0].setX(this->getX());
        this->_subButtons[0].setY(this->getY());
        this->_subButtons[0].setImagePath(":/Image/pictures/S_PuNi.png");//进化版：S谱尼
        break;
    }
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    {
        this->_subButtons[0].setX(this->getX());
        this->_subButtons[0].setY(this->getY());
        this->_subButtons[0].setImagePath(":/Image/pictures/lock.png");//无进化版
        break;
    }

    default:
        break;
    }
    this->_subButtons[1].setX(this->getX());
    this->_subButtons[1].setY(this->getY()+2*PIX);
    this->_subButtons[1].setImagePath(":/Image/pictures/recycle.png");//回收按钮

    this->_display = true; //显示状态设为真
}

int EnvovleBox::getType()const{
    return this->_type;
}

//获取横坐标
int EnvovleBox::getX()const{
    return this->_p.getX();
}

//获取纵坐标
int EnvovleBox::getY()const{
    return this->_p.getY();
}

//获取选择框图片路径
QString EnvovleBox::getImgPath()const{
    return this->_imagePath;
}

//获取显示状态
bool EnvovleBox::getDisplay()const{
    return this->_display;
}

//设置显示状态
void EnvovleBox::setDisplay(const bool tf){
    this->_display=tf;
}

//获取子按钮结构数组
SubButton* EnvovleBox::getSubButtons(){
    return this->_subButtons;
}