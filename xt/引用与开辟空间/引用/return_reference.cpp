//常引用(常引用) 安全 不能对常引用对象作直接修改
//如下
// int a;
// const int& &ra=a;
//ra=1;  错误常引用不能直接修改
//a=1; //正确

//引用作为返回值
//只有类里面的方法可以返回引用，并且引用对象为类成员变量（防止返回的时候，一些对象被释放掉，从而产生错误）
//对于一般的函数调用，返回引用将会导致编译出错

//可以使用常引用进行限定 ，const int& 防止返回对象被修改，也就是原来的对象被修改（安全了）
//程序在能被定义为const的情况下，经量定义为const，安全为重


//引用与多态
//指针与多态 都可以

#include <iostream>

using namespace  std;


int x;
int &f()
{
    x=4;
    return x;
}  //返回x的引用，这个也是可以，因为全局值，没有被释放掉  有些编译器是不可以的，奇怪

int &f2()
{
    int y=4;
    return y; 
} //不可以局部变量会被释放掉


class A
{
public:
    int x;

    int &f()
    {
        x=3;
        return x;
    }
};

int main()
{
    int b=f();
    cout<<b<<endl; //正确

    //int c=f2();
    //cout<<c<<endl;  //错误

    A a;
    int y=a.f();
    cout<<y<<endl;

    //常引用不能改变
    int aa=3;
    const int &bb=aa;
   //b=4;  //常引用不可知作出修改
}
