/*
* ����ģʽ��
* ˵������ֹ������Ĺ��캯��/�������캯��/������=����Ϊpublic��ͨ���ṩ��public static�ӿ�GetInstance��ȡ��������
*       ����ģʽ��ʹ��ʱ�Ź������ʼ��������ģʽ����������ʱ�������ʼ����
* �ô�����֤һ��������ֻ����һ��ʵ����
* ���⣺1.���߳�ʹ��ʱ����α�֤�̰߳�ȫ��˫��������֤�̰߳�ȫ��
        2.�����๹�캯������Ҫ�����������ʵ�֣�ģ����ʵ�ֶ�����������졣
*/
#include <stdio.h>
#include <assert.h>

/*
* ��֧�����๹�캯��������
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
    * �˴��������ã������ⲿdeleteָ�����
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
* ֧�����๹�캯����������
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
* ���̰߳�ȫ��˫������
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
private:
    SingletonT(const SingletonT &ot) {}
    SingletonT& operator = (const SingletonT &ot) {}
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

/*
* ����ģʽ
*/
template <class T>
class SingletonH
{
protected:
    SingletonH() {}
    virtual ~SingletonH() {}
private:
    SingletonH(const SingletonH &ot) {}
    SingletonH& operator = (const SingletonH &ot) {}
public:
    static T& GetInstance()
    {
        return *m_pInstance;
    }
private:
    static T* m_pInstance;
};
template<class T>
T* SingletonH<T>::m_pInstance = new T();

class Log : public SingletonH<Log>
{
    friend class SingletonH<Log>;
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