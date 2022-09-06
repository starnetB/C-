#include <iostream>

using namespace std;

//C++11 之前，派生类没法直接继承构造函数
class Base{
public:
    Base(int ma):ma_(ma) { cout << "Base(int)" << endl; }
    Base(int ma, double mb) :ma_(ma), mb_(mb) { cout << "Base(int,double)" << endl; }
    Base(int ma, double mb, std::string str):ma_(ma), mb_(mb), mstr_(str) { cout << "Base(int,double,string)" << endl;}
    void fun(float p) { cout << "Base::fun" << endl; }
    void fun(float p, int a) { cout << "Base::fun" << endl; }
private:
    int ma_;
    double mb_;
    std::string mstr_;
};

//继承的时候，需要对每个父类构造函数进行明写，
class Deriver1:public Base{
public:
    Deriver1(int i):Base(i){}
    Deriver1(int i, double j) :Base(i, j) { cout << "Deriver1(int,double)" << endl; }
    Deriver1(int i, double j, string k) :Base(i, j, k) { cout << "Deriver1(int,double,string)" << endl; }
};

//C++11 之后可以通过using 命令直接写

class Deriver2:public Base{
    using Base::Base;
};


//也可以显式将父类方法变成自己的，（这个功能很鸡肋
class Deriver3:public Base{
public:
    using Base::Base;
    //这个功能停鸡肋的，父类方法也可以被继承下来，你不去改写就可以了
    using Base::fun;

    void fun(int p){cout<<"Deriver3::fun"<<endl;}
};
int main(){
    Deriver2 d1(10);
    Deriver2 d2(10,0.0);
    Deriver2 d3(10,0.0,"string");
    return 0;
}