#include <iostream>

//简单的单例模式
class Single
{
private:
    Single(){}

    ~Single(){}

    //这里可以添加线程安全的数据
    Single(const Single &);
    Single & operator=(const Single &);
public:
    //单例工厂的具体实现
    static Single& GetInstance()
    {
        static Single instance;
        return instance;
    }

    void doS()
    {
        std::cout<<"1111111111"<<std::endl;
    }
};


int main()
{
    Single::GetInstance().doS();
}