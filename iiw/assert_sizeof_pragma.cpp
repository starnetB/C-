#define NDEBUG
#include <assert.h>
#include <iostream>

using namespace std;

#pragma pack(push)
#pragma pack(8)
struct test
{
    char m1;
    double m4;
    int m3;
};
#pragma pack(pop)

//位域
struct  Demo
{
    unsigned int a:1;
    unsigned int b:4;
    unsigned int c:6;
    unsigned int  :4;
};

//a占有一个bit
//b占有二个bit
//c占有6个bit
//但是c由于和前面两个加起来超过一个字节了，所以应该从第二个字节开始
//最后一个不能使用，智能当作占位作用
int main()
{
    //int *p=new int(10);
    int *p;
    assert(p!=NULL);

    cout<<"================="<<endl;

    //sizeof
    int aa[10];
    int *ap=new int(10);

    cout<<"array"<<endl;
    cout<<sizeof(aa)<<endl;
    cout<<"ap"<<endl;
    cout<<sizeof(ap)<<endl;
    delete ap;
    cout<<"================"<<endl;
    //类成员变脸以n字节的方式对齐
    test t;
    cout<<sizeof(t.m1)<<endl;
    cout<<sizeof(t.m4)<<endl;
    cout<<sizeof(t.m3)<<endl;
    cout<<sizeof(t)<<endl;
    

    //注意位域溢出问题
    Demo d;
    d.a=2;
    d.b=6;
    d.c=4;

    cout<<d.a<<"\t"<<d.b<<"\t"<<d.c<<endl;
}