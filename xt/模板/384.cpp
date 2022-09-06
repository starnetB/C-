// 模板函数是对算法的封装，部队数据类型作规定

#include <iostream>

template <class T>
T add(const T& a,const T& b)
{
    return a*b;
}

template <typename T>
T max(T array[],int n)
{
    T m;
    m=array[0];
    for(int i=0;i<n;i++)
    {
        if(m<array[i])
            m=array[i];
    }
    return m;
}

template <typename T>
T sum(T array[],int n)
{
    T all;
    for(int i=0;i<n;i++)
    {
        all=all+array[i];
    }
    return all;
}

int main()
{
    int a[4]={33,1,5,87};
    double b[3]={3.33333,111.1111,5.55555};
    int c=max(a,4);
    double d=max(b,3);
    std::cout<<c<<std::endl;
    std::cout<<d<<std::endl;

    int x=sum(a,4);
    double y=sum(b,3);
    std::cout<<x<<std::endl;
    std::cout<<y<<std::endl;

}
