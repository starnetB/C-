#include <iostream>
using namespace std;

void otherdef(int & t){
    std::cout<<"lvalue"<<std::endl;
}

void otherdef(int &&t)
{
    std::cout<<"rvalue"<<std::endl;
}

//实现完美转发
template <typename T>
void function(T&& t)
{
    otherdef(forward<T>(t));
}

int main()
{
    function(5);

    int a1=10;
    int a2=20;
    int &&y=a1+a2;
    function(y);

    int x=1;
    function(x);

    int a=10;
    int &b=a;
    function(b);
}