#include <iostream>

int count=11;

class A{
public:
    static int count;
};

int A::count=21;

void fun()
{
    int count=31;
    count=32;
}


int main(){
    ::count=12; //全局
    A::count=22;  //类静态
    fun();   //局部

    return 0;
}