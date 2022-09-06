#include <iostream>

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
//重载参数和返回值不一样
int main()
{
    int a=3;
    int b=4;
    int c=5;
    float x=1.1111;
    float y=2.2222;

    int m=add(a,b);
    int n=add(a,b,c);
    float l=add(x,y);
    std::cout<<m<<std::endl;
    std::cout<<n<<std::endl;
    std::cout<<l<<std::endl;
}