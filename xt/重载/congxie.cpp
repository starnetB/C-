#include <iostream>

class A
{
public:
    void f()
    {
        std::cout<<"前熟练"<<std::endl;
    }

    virtual void f1()
    {
        std::cout<<"1111111111111111111111111"<<std::endl;
    }
};

class B:public A{
public:
    void f(){
        std::cout<<"dddddddddddddd"<<std::endl;
    }

    virtual void f1()
    {
        std::cout<<"222222222222222222222222222"<<std::endl;
    }
};

int main()
{
    A a;
    B b;
    A * bb=new B();
    a.f();
    b.f();
    bb->f();

    a.f1();
    bb->f1();
}