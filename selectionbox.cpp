#include "selectionbox.h"

SelectionBox::SelectionBox(QString imagePath):
    _p(0,0),_imagePath(imagePath){}

//选中防御塔
void SelectionBox::clickOne(int x, int y)
{
    //确定选择框的位置（左上角）
    this->_p.setX(x+64);
    this->_p.setY(y-2*64);

    //确定子按钮的位置
    //萌布布种子：左上
    this->_subButtons[0].setX(this->getX());
    this->_subButtons[0].setY(this->getY());
    this->_subButtons[0].setImagePath(":/Image/pictures/MengBuBuZhongZi.png");


    this->_display = true; //显示状态设为真
}

//获取横坐标
int SelectionBox::getX()const{
    return this->_p.getX();
}

//获取纵坐标
int SelectionBox::getY()const{
    return this->_p.getY();
}

//获取选择框图片路径
QString SelectionBox::getImgPath()const{
    return this->_imagePath;
}

//获取显示状态
bool SelectionBox::getDisplay()const{
    return this->_display;
}

//设置显示状态
void SelectionBox::setDisplay(const bool tf){
    this->_display=tf;
}

//获取子按钮结构数组
SubButton* SelectionBox::getSubButtons(){
    return this->_subButtons;
}