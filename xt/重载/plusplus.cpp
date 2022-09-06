#include <iostream>

class A
{
    int v;
public:
    A()
    {
        v=0;
    }

    void disp()
    {
        std::cout<<v<<std::endl;
    }
    //前置的++ 我们先进行++，后进行返回，所以我们返回本身
    A operator++()
    {
        std::cout<<"forward"<<std::endl;
        //先++
        v++;
        //后返回，返回的是当前的值
        return *this;
    }
    //通过函数中整形来确定，是后置的++函数
    //由于后置的++由于先返回，后形成对象，所以在后置的++中我们生成了对象
    A operator++(int n)
    {
        std::cout<<"black"<<std::endl;
        //后置的++，先返回
        A tmp=*this;
        //后++
        v++;
        //返回的是老的值
        return tmp;
    }
};

int main()
{
    A a;
    for(int i=0;i<10;i++)
    {
        //后置的++，我们先要执行函数，并返回，这个动作
        (a++).disp();
        a.disp(); //A本身是一样的，都是直接加上一
    }

    A a2;
    for(int i=0;i<10;i++)
    {
        (++a2).disp();
        a2.disp(); //A本身是一样的
    }
}