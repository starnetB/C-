#include <iostream>
//通过虚继承解决二义性，解决重复拷贝的问题
class A
{
public:
    void f()
    {
        std::cout<<"aaaaaaaaaaaaa"<<std::endl;
    }
};

class B:virtual public A
{};

class C:public virtual A  //两种写法都性
{};

class D:public B,public  C
{};

int main()
{
    D d;
    d.f(); //解决了二义性
    d.B::f();  //可以解决二义性
    d.C::f();
    
}