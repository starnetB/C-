//左值引用和右值引用

// 不能把引用名作为其他变量的别名


//引用的唯一性，两个名字实际上代表的是同一个对象
//一个改变，另一个跟着一起改变


//引用与数组
//不能建立数组的引用，但可以对一个对象建立引用
//引用没有副本的问题，占用的同一个对象空间


//引用与初始化

//引用必须在定义的马上被初始化，因为它必须是某个东西的同义词。你不能先定义一个引用后才去初始化它。

#include <stdio.h>
#include <iostream>

class A
{
public:
    int x;
    int y;
    void disp()
    {
        std::cout<<x<<":"<<y<<std::endl;
    }
};


int main()
{
    int x=3;
    int &y=x;

    std::cout<<"x:"<<x<<std::endl;
    std::cout<<"y:"<<y<<std::endl;
    std::cout<<&x<<std::endl;
    std::cout<<&y<<std::endl;

    x=33;
    std::cout<<"x:"<<x<<std::endl;
    std::cout<<"y:"<<y<<std::endl;
    y=333;
    std::cout<<"x:"<<x<<std::endl;
    std::cout<<"y:"<<y<<std::endl;
    
    A a1;
    a1.x=3;
    a1.y=4;

    A &a2=a1;
    a1.disp();
    a2.disp();

    a2.x=33;
    a2.y=44;
    a1.disp();
    a2.disp();
}