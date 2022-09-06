//new 
//delete
#include <iostream>

class A
{
public:
    int x;
    int y;

};

int main()
{
    //基本变量的开辟
    int *p=new int;
    char *c=new char;

    //释放
    delete p;
    delete c;

    int *p2=new int[10];
    for(int i=0;i<10;i++)
    {
        p2[i]=i*2;
        std::cout<<p2[i]<<"\t";
    }
    std::cout<<std::endl;
    delete [] p2;

    A *pa=new A();
    pa->x=3;
    pa->y=4;
    std::cout<<pa->x<<":"<<pa->y<<std::endl;

    delete pa;

    A *pb=new A[10];
    delete [] pb;
    return 0;
}