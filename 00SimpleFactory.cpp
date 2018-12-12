/*
* 简单工厂模式，该模式不属于23种设计模式。
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