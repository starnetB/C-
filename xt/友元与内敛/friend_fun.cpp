#include <iostream>

using namespace std;

//友元函数的声明，可以放在类的共有部分，也可以放在类的私有部分
//它们是没有区别的

//一个函数可以多个类的友元函数
//只需要在各个类中分别声明就可以了 

//友元是一种定义在类外部的普通函数或类，但它需要在类体内进行说明，为了与该类的成员函数加以却别
//在说明时，前面加上friend字样


//友元是单向，A是B的友元，B不一定是A的友元

//友元不具备传递性，C是B的友元，B是A的友元，但C不一定是A的友元，除非强制定义

//友元破坏封装性

#include <iostream>
using namespace std;
class A
{
public:
    void f1()
    {

    }
private:
    int x;
    int y;

    void f2()
    {

    }
};
class B;

void doB(B b);

class B
{
public:
    friend void doB(B b);
    B(int a,int b)
    {
        x=a;
        y=b;
    }
private:
    int x;
    int y;
    void f3()
    {
        cout<<"kkkkkkkkkkkkkk"<<endl;
    }
};

void doB(B b)
{
    cout<<":"<<b.x<<":"<<b.y<<endl;
    b.f3();
}

int main()
{
    A a;
    a.f1();
    B b(1,2);
    doB(b);
    //a.f2();  // 私有成员，没法访问
    return 0;
}