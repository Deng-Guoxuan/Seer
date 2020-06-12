#ifndef SELECTIONBOX_H
#define SELECTIONBOX_H

#include "point.h"
#include "subbutton.h"

class SelectionBox
{
public:
    SelectionBox(QString imagePath);//构造
    int getX()const;//获取横坐标
    int getY()const;//获取横坐标

    bool getDisplay()const;//获取显示状态

    void setDisplay(const bool tf); //设置显示状态
    void clickOne(int x, int y);//选中一个位置

    QString getImgPath()const; //获取选择框图片路径
    SubButton* getSubButtons();//获取子按钮结构数组

private:
    bool _display = false;   //是否显示
    Point _p;//选择框最左上角坐标
    QString _imagePath;//图片路径
    SubButton _subButtons[6];    //6个子按钮
};


#endif // SELECTIONBOX_H