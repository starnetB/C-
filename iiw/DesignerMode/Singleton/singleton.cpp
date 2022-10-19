#include <iostream>

class Singleton{
private:
    Singleton(){}

    ~Singleton(){}

    //这里可以添加线程安全的数据锁等
    Singleton(const Singleton &);
    Singleton & operator=(const Singleton &);
public:
    //单例工厂的具体实现
    static Singleton & GetInstance()
    {
        static Singleton instance;
        return instance;
    }

    void DoSomething();
};

void Singleton::DoSomething()
{
    std::cout<<"222222222222"<<std::endl;
}

void SingleToMain()
{
    Singleton::GetInstance().DoSomething();
}

int main()
{
    SingleToMain();
}
