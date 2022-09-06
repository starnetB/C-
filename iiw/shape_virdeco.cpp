// virtual deconstructor function

#include<iostream>

class Shape
{
public:
    Shape()
    {
        std::cout<<"1111"<<std::endl;
    };
    virtual double calcArea()
    {
        return 10.11;
    };
    //可以把 virtual 去掉看看
    //结果会只是调用父类的析沟函数，子类的就会不调用，所以父类西沟函数必须是virtual
    virtual ~Shape()
    //~Shape()
    {
        std::cout<<"first deconstructor!"<<std::endl;
    };

};


class Circle:public Shape
{
public:
    Circle(){}
    Circle(double r){
        std::cout<<r<<std::endl;
    }
    virtual double calcArea()
    {
        return 12.11;
    }

    ~Circle(){
        std::cout<<"second "<<std::endl;
    }
};


int main()
{
    Shape *a=new Circle(4.0);
    auto b=a->calcArea();
    std::cout<<b<<std::endl;

    delete a;
    a=NULL;
    return 0;
}