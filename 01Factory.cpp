/*
* 工厂模式。
* 描述：定义产品基类与工厂基类，不同的产品使用不同工厂生产，产品继承产品基类，工厂继承工厂基类。
* 好处：屏蔽了生产细节。新增产品无需修改工厂方法。使用产品基类指针可多态化产品的具体方法。使用工厂基类多态化工厂的具体方法。
* 问题：新增产品，则需要新增工厂。
*/
#include <stdio.h>

class Mouse
{
public:
    Mouse() {}
    virtual ~Mouse() {}
public:
    virtual void Click() = 0;
};

class MouseFactory
{
public:
    MouseFactory() {}
    virtual ~MouseFactory() {}
public:
    virtual Mouse* Create() = 0;
};

class DellMouse : public Mouse
{
public:
    DellMouse() {}
    virtual ~DellMouse() {}
public:
    void Click()
    {
        printf("Dell mouse click.\n");
    }
};

class HPMouse :public Mouse
{
public:
    HPMouse() {}
    virtual ~HPMouse() {}
public:
    void Click()
    {
        printf("HP mouse click.\n");
    }
};

class DellMouseFactory: public MouseFactory
{
public:
    DellMouseFactory() {}
    virtual ~DellMouseFactory() {}

public:
    virtual Mouse* Create()
    {
        return new DellMouse();
    }
};

class HPMouseFactory : public MouseFactory
{
public:
    HPMouseFactory() {}
    virtual ~HPMouseFactory() {}
public:
    virtual Mouse* Create()
    {
        return new HPMouse();
    }
};

int main()
{
    MouseFactory *pDellMouFac = new DellMouseFactory();
    MouseFactory *pHPMouFac = new HPMouseFactory();
    Mouse *pDellMouse = pDellMouFac->Create();
    Mouse *pHPMouse = pHPMouFac->Create();
    pDellMouse->Click();
    pHPMouse->Click();
    return 0;
}