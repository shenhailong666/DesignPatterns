/*
* 简单工厂模式，该模式不属于23种设计模式。
* 实现：定义产品基类，产品继承此类，工厂根据传入参数生产对应产品。
* 好处：屏蔽生产细节。使用产品基类指针可多态化产品的具体方法。
* 问题：新增产品时，需要修改工厂方法，破坏了开闭原则。
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

class Mouse
{
public:
    Mouse() {}
    virtual ~Mouse() {}
public:
    virtual void Click() = 0;
};

class DellMouse: public Mouse
{
public:
    DellMouse() {}
    virtual ~DellMouse() {}
public:
    virtual void Click()
    {
        printf("Dell mouse click.\n");
    }
};

class HPMouse: public Mouse
{
public:
    HPMouse() {}
    virtual ~HPMouse() {}
public:
    virtual void Click()
    {
        printf("HP mouse click.\n");
    }
};

class MouseFactory
{
public:
    MouseFactory() {}
    virtual ~MouseFactory() {}
public:
    Mouse* Create(const char *pName)
    {
        if (0 == strcmp(pName, "Dell"))
        {
            return new DellMouse();
        }
        else if (0 == strcmp(pName, "HP"))
        {
            return new HPMouse();
        }
        else
        {
            return NULL;
        }
    }
};

int main()
{
    MouseFactory MouseFac;
    Mouse *pDellMouse = MouseFac.Create("Dell");
    Mouse *pHPMouse = MouseFac.Create("HP");
    pDellMouse->Click();
    pHPMouse->Click();
    return 0;
}