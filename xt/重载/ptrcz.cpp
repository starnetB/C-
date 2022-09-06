//原来的->不会改变的
//重点扩展功能
//添加二次指向
#include<iostream>

class A
{
public:
    int x;
    A(){}
    A(int x)
    {
        this->x=x;
    }

    A* operator->()
    {
        return this;
    }
};

class B
{
    A a;
    int y;
public:
    B(A a)
    {
        this->a=a;
    }
    A operator->()
    {
        return a;
    }
};

int main()
{
    A a(30);
    B b(a);
    std::cout<<b->x<<std::endl;  //三次调用，b->a  a->this  this->x
}