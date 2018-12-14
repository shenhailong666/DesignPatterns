/*
* 单例模式。
* 说明：禁止单例类的构造函数，拷贝构造函数，操作符=为public。通过提供的public static接口GetInstance获取单例对象。
* 好处：保证一个进程中只存在一个实例。
* 问题：多线程使用时，如何保证线程安全。单例类构造函数若需要传参数，如何实现。
*/
#include <stdio.h>
#include <assert.h>

template<class T>
class Singleton
{
protected:
    Singleton() {}
    virtual ~Singleton() {}
private:
    Singleton(const Singleton &ot) {}
    Singleton& operator = (const Singleton &ot) {}
public:
    /*
    * 此处返回引用，避免外部delete指针对象
    */
    static T& GetInstance()
    {
        if (NULL == m_pInstance)
        {
            m_pInstance = new T;
            assert(NULL != m_pInstance);
        }
        return *m_pInstance;
    }
private:
    static T *m_pInstance;
};

template <class T>
T* Singleton<T>::m_pInstance = NULL;

class Log : public Singleton<Log>
{
public:
    Log() {}
    virtual ~Log() {}
public:
    void WriteLog()
    {
        printf("Write log.\n");
    }
};

int main()
{
    Log::GetInstance().WriteLog();
    return 0;
}