#include <iostream>

using namespace std;

class B;

class A
{  
public:
    inline void F(B b);
    
};

class B
{
public:
    //直接声明有元函数就可以了
    //friend void A::F(B b);
    B(int a,int b)
    {
        x=a;
        y=b;
    }
private:
    //有元类也可以，都可以访问私有成员，A类的所有成员都可以访问另外一个类的私有成员
    //有元类往往在重载的操作符上起到很大的作用
    friend class A;
    int x;
    int y;
};

//有元关系不能被继承
//基类的友元对派生类的成员没有特殊的访问权限
//基类被授予友元关系，则只有基类具有特殊的访问权限，该基类的派生类不能访问授予友元关系的类

class BB;

class AA
{
public:
    void f1(BB b);
    void f2(BB b);
    void f3(BB b);
};

class BB
{
public:
    BB(int a,int b)
    {
        x=a;
        y=b;
    }
private:
    friend class AA;
    int x;
    int y;
};

void AA::f1(BB b)
{
    cout<<b.x<<":"<<b.y<<endl;
}

void AA::f2(BB b)
{
    cout<<b.x<<":"<<b.y<<endl;
}

void AA::f3(BB b)
{
    cout<<b.x<<":"<<b.y<<endl;
}


//只是确保B 中的b.x 和b.y 已经能够被访问到，所以放在外面
inline void A::F(B b)
{
    cout<<b.x<<":"<<b.y<<endl;
}

int main()
{
    /*
    B b(1,2);
    A a;
    a.F(b);*/
    BB bb(1,2);
    AA aa;
    aa.f1(bb);
    aa.f2(bb);
    aa.f3(bb);
    return 0;
}