#include <iostream>

class Array
{
    int *p;
    int length;
public:
    //Array(){}

    Array(int size=10)
    {
        length=size;
        p=new int[size];
    }

    void disp()
    {
        for(int i=0;i<length;i++)
        {
            std::cout<<p[i]<<"\t";
        }

        std::cout<<std::endl;
    }

    int & operator[](int index)
    {
        return p[index];
    }
};

int main()
{
    Array a(15);
    for(int i=0;i<15;i++)
    {
        a[i]=i;
    }

    a.disp();
}