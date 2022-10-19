#include <iostream>
//没有使用虚继承，重复拷贝，同时出现二义性的问题
class A
{
public:
    void f()
    {
        std::cout<<"aaaaaaaaaaaaa"<<std::endl;
    }
};

class B:public A
{};

class C:public A
{};

class D:public B,public C
{};

int main()
{
    D d;
    //d.f(); //错误出现而二义性
    d.B::f();  //可以解决二义性 //但没法解决重复拷贝的问题
    d.C::f();
}