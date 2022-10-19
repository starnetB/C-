#include <iostream>

//实现继承
//正常的继承，子类可以使用父类的很多方法等

//接口继承，就是父类是纯虚类，子类必须实现父类的所有方法
//可视继承，是指子窗体使用基窗体的外观和实现代码的能力，这种一般在可视化界面中用的比较多

//重载是一种静态多态
class A
{
public:
    void do1(int a);
    void do1(int a,int b);
};

void A::do1(int a)
{
    std::cout<<a<<std::endl;
}

void A::do1(int a,int b)
{
    std::cout<<b<<std::endl;
}

A get_A()
{   
    A a;
    return a;
}

/*
int main()
{
    A &&a=std::move(get_A());
    a.do1(3);
    a.do1(3,4);
}*/


//动态多台(运行期间/晚绑定)

class Shape
{
public:
    Shape(){}
    Shape(int aa):aa(aa){}
    virtual double calcArea()
    {
        std::cout<<33<<std::endl;
        return 33;
    }

    virtual ~Shape(){};
private:
    int aa;
};


class Circle:public Shape
{
public:
    using Shape::Shape;
    Circle(int a,int b):Shape(a),b(b){}
    virtual double calcArea();
private:
    int b;
};

class Rect:public Shape
{
public:
    using Shape::Shape;
    Rect(int a,int c):Shape(a){
        this->c=c;
    }
    virtual double calcArea()
    {
        std::cout<<c<<std::endl;
        return 33;
    }
private:
    int c;
};

double Circle::calcArea()
{
    std::cout<<b<<std::endl;
    return 33;
}

int main()
{
    Shape *shape1=new Circle(1,2);
    Shape *shape2=new Rect(1,3);
    shape1->calcArea();
    shape2->calcArea();
    delete shape1;
    shape1=nullptr;
    delete shape2;
    shape2=nullptr;

    Circle c3(44,44);
    Shape &shape3=c3;
    shape3.calcArea();
    return 0;
}