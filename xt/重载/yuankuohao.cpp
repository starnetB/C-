#include <iostream>

class F 
{
public:
    F(){}
    F(int a,int b){}

    int operator()(int a,int b);
};

int F::operator()(int a,int b)
{
    return a*b;
}

int main()
{
    F f(1,2);

    int x=f(3,4);
    std::cout<<x<<std::endl;
}