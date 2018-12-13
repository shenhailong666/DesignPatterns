/*
* 抽象工厂模式。
* 描述：定义产品基类，定义工厂基类。产品继承产品基类，工厂继承工厂基类。一个工厂可生产多种产品。
* 好处：屏蔽生产细节。新增产品无需修改工厂方法，也无需新增工厂。使用产品基类多态化产品的具体方法，使用工厂基类多态化工厂的具
* 体方法。可扩展新工厂。
* 问题：增加了逻辑与结构复杂度。工厂基类增加生产新产品接口，则该继承工厂类都会继承该生产接口。
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

class KeyBoard
{
public:
    KeyBoard() {}
    virtual ~KeyBoard() {}
public:
    virtual void PressEnter() = 0;
};

class DigitalFactory
{
public:
    DigitalFactory() {}
    virtual ~DigitalFactory() {}
public:
    virtual Mouse* CreateMouse() = 0;
    virtual KeyBoard* CreateKeyBoard() = 0;
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

class HPMouse : public Mouse
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

class DellKeyBoard : public KeyBoard
{
public:
    DellKeyBoard() {}
    virtual ~DellKeyBoard() {}
public:
    virtual void PressEnter()
    {
        printf("Dell keyboard press enter.\n");
    }
};

class HPKeyBoard : public KeyBoard
{
public:
    HPKeyBoard() {}
    virtual ~HPKeyBoard() {}
public:
    virtual void PressEnter()
    {
        printf("HP keyboard press enter.\n");
    }
};

class DellDigitalFactory: public DigitalFactory
{
public:
    DellDigitalFactory() {}
    virtual ~DellDigitalFactory() {}
public:
    virtual Mouse* CreateMouse()
    {
        return new DellMouse();
    }
    virtual KeyBoard* CreateKeyBoard()
    {
        return new DellKeyBoard();
    }
};

class HPDigitalFactory: public DigitalFactory
{
public:
    HPDigitalFactory() {}
    virtual ~HPDigitalFactory() {}
public:
    Mouse* CreateMouse()
    {
        return new HPMouse();
    }
    KeyBoard* CreateKeyBoard()
    {
        return new HPKeyBoard();
    }
};

int main()
{
    DigitalFactory *pDellDigFac = new DellDigitalFactory();
    DigitalFactory *pHPDigFac = new HPDigitalFactory();
    Mouse *pDellMouse = pDellDigFac->CreateMouse();
    Mouse *pHPMouse = pHPDigFac->CreateMouse();
    KeyBoard *pDellKeyBoard = pDellDigFac->CreateKeyBoard();
    KeyBoard *pHPKeyBoard = pHPDigFac->CreateKeyBoard();
    pDellMouse->Click();
    pHPMouse->Click();
    pDellKeyBoard->PressEnter();
    pHPKeyBoard->PressEnter();
    return 0;
}