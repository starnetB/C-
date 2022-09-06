//内联函数执行速度快
//一般函数通过断点和返回，这个函数体的调用会浪费性能
//内联函数的局限性，如果内联函数体过大，编译器就会自动放弃内联方式，把函数变成普通函数

//内联函数的优缺点
//优点 内敛函数尽量简单吧

//使用内敛函数，不过是向编译器提出一个申请，
//# pragma auto_inline 自动禁止内敛

//内敛尽量不用循环语句 ，开关switch
//嵌套，递归也尽量不要使用

//内敛函数与宏
//内敛函数可以取代宏
//调用直接就是普通函数
//内敛函数，比宏开销大，比普通函数开销小
//如果编译器可以拒绝内敛请求

#include <iostream>
#include <stdio.h>

using namespace std;

void f1()
{
    std::cout<<"11111111111111111"<<endl;
}

//全局函数作内敛识别
inline void f2()
{
    cout<<"22222222222222222"<<endl;
}

//成员内敛
class A
{
public:
    //类内部实现，自动内敛
    void f1()
    {
        cout<<"aaaaaaaaaaaaaaaaa"<<endl;
    }
    //类内部实现，续函数，不自动内敛
    virtual void f2()
    {
        cout<<"bbbbbbbbbbbbbbbbbbbbbb"<<endl;
    }

    void f3();

    inline void f4();
};

//类体外函数，不自动内敛
void A::f3(){
    cout<<"ccccccccccccccccc"<<endl;
}

//显示内敛
inline void A::f4()
{
    cout<<"ddddddddddddddd"<<endl;
}

int main()
{
    f1();
    //自动代码copy到这个地方
    f2();

    A a1;
    a1.f1();
    a1.f2();
    a1.f3();
    a1.f4();
}
