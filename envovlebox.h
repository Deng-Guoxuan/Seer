#ifndef ENVOVLEBOX_H
#define ENVOVLEBOX_H

//进化以及移除精灵的选择框

#include "point.h"
#include "subbutton.h"

class EnvovleBox
{
public:
    EnvovleBox(QString imagePath);//构造
    int getX()const;//获取横坐标
    int getY()const;//获取横坐标
    int getType()const;//确定要升级的精灵类型

    bool getDisplay()const;//获取显示状态

    void setDisplay(const bool tf); //设置显示状态
    void clickOne(int x, int y, int id);//选中一个位置,且传入当前精灵类型

    QString getImgPath()const; //获取选择框图片路径
    SubButton* getSubButtons();//获取子按钮结构数组

private:
    bool _display = false;   //是否显示
    int _type=0;//要升级的精灵类型
    Point _p;//选择框最左上角坐标
    QString _imagePath;//图片路径
    SubButton _subButtons[2];    //2个子按钮
};

#endif // ENVOVLEBOX_H


#include "point.h"
#include "subbutton.h"

