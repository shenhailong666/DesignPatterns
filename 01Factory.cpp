/*
* ����ģʽ��
* �����������Ʒ�����빤�����࣬��ͬ�Ĳ�Ʒʹ�ò�ͬ������������Ʒ�̳в�Ʒ���࣬�����̳й������ࡣ
* �ô�������������ϸ�ڡ�������Ʒ�����޸Ĺ���������ʹ�ò�Ʒ����ָ��ɶ�̬����Ʒ�ľ��巽����ʹ�ù��������̬�������ľ��巽����
* ���⣺������Ʒ������Ҫ����������
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