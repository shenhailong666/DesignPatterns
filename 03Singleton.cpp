/*
* 单例模式。
* 说明：禁止单例类的构造函数/拷贝构造函数/操作符=函数为public。通过提供的public static接口GetInstance获取单例对象。
* 好处：保证一个进程中只存在一个实例。
* 问题：1.多线程使用时，如何保证线程安全？双重锁定保证线程安全。
        2.单例类构造函数若需要传参数，如何实现？模板变参实现多参数单例构造。
*/
#include <stdio.h>
#include <assert.h>

/*
* 不支持子类构造函数带参数
*/
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

/*
* 支持子类构造函数带参数。
*/
template <class T>
class SingletonArg
{
protected:
    SingletonArg() {}
    virtual ~SingletonArg() {}
private:
    SingletonArg(const SingletonArg &ot) {}
    SingletonArg& operator = (const SingletonArg &ot) {}
public:
    template<class ...Args>
    static T& GetInstance(Args&&... args)
    {
        if (NULL == m_pInstance)
        {
            m_pInstance = new T(args...);
            assert(NULL != m_pInstance);
        }
        return *m_pInstance;
    }
private:
    static T *m_pInstance;
};
template <class T>
T* SingletonArg<T>::m_pInstance = NULL;

/*
* 多线程安全，双重锁定
*/
class SpinLock
{
public:
    SpinLock() {}
    ~SpinLock() {}
    void Lock() {}
    void UnLock() {}
};

template<class T>
class SingletonT
{
protected:
    SingletonT() {}
    virtual ~SingletonT() {}
public:
    static T& GetInstance()
    {
        if (NULL == m_pInstance)
        {
            m_Lock.Lock();
            if (NULL == m_pInstance)
            {
                m_pInstance = new T();
                assert(NULL != m_pInstance);
            }
            m_Lock.UnLock();
        }
        return *m_pInstance;
    }
private:
    static T* m_pInstance;
    static SpinLock m_Lock;
};
template <class T>
T* SingletonT<T>::m_pInstance = NULL;
template <class T>
SpinLock SingletonT<T>::m_Lock;

class Log : public SingletonT<Log>
{
    friend class SingletonT<Log>;
protected:
    Log()
    {
        printf("No args constructor.\n");
    }
    Log(const char *pFileName)
    {
        printf("Args constructor.\n");
    }
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