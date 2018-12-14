/*
* ����ģʽ��
* ˵������ֹ������Ĺ��캯�����������캯����������=Ϊpublic��ͨ���ṩ��public static�ӿ�GetInstance��ȡ��������
* �ô�����֤һ��������ֻ����һ��ʵ����
* ���⣺���߳�ʹ��ʱ����α�֤�̰߳�ȫ�������๹�캯������Ҫ�����������ʵ�֡�
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