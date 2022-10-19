#include <iostream>


class A
{
public:
    int add(int a,int b)
    {
        return a+b;
    }

    int add(int a,int b,int c)
    {
        return a+b+c;
    }

    float add(float a,float b)
    {
        return a+b;
    }
};

int main()
{
    int a=3;
    int b=4;
    int c=5;
    
    float x=1.11111;
    float y=2.22222;

    A n;
    std::cout<<n.add(a,b)<<std::endl;
    std::cout<<n.add(a,b,c)<<std::endl;
    std::cout<<n.add(x,y)<<std::endl;
}