#include <stdio.h>
#include <iostream>
using namespace std;

int a=3;
int b=4;

void f(int &x,int &y)
{
    x++;
    y++;
}

void swap(int *x,int *y)
{
    int temp1=*x;
    int temp2=*y;
    *x=temp2;
    *y=temp1;
}

class A
{
    int a[20000];
};

void f1(A a)
{}

void f2(A a)
{}

int main()
{
    f(a,b);
    cout<<a<<":"<<b<<endl;

    swap(&a,&b);
    cout<<a<<":"<<b<<endl;

    A a;
    f1(a);
    f2(a);
    return 0;
}