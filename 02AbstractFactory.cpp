/*
* ���󹤳�ģʽ��
* �����������Ʒ���࣬���幤�����ࡣ��Ʒ�̳в�Ʒ���࣬�����̳й������ࡣһ���������������ֲ�Ʒ��
* �ô�����������ϸ�ڡ�������Ʒ�����޸Ĺ���������Ҳ��������������ʹ�ò�Ʒ�����̬����Ʒ�ľ��巽����ʹ�ù��������̬�������ľ�
* �巽��������չ�¹�����
* ���⣺�������߼���ṹ���Ӷȡ������������������²�Ʒ�ӿڣ���ü̳й����඼��̳и������ӿڡ�
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