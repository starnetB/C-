//数组，连续存储+同一类型
#include <iostream>

template <typename T>
class Array
{
private:
    T *sell;
    int n;
public:
    Array(T *a,int n)
    {
        sell=a;
        this->n=n;
    }

    ~Array(){}

    void seek(T t);
    void sort();
    void print();
    void sum();
};

template <class T>
void Array<T>::seek(T t)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(sell[i]==t)
        {
            std::cout<<"position"<<i<<std::endl;
        }
    }
    if(i>=n)
    {
        std::cout<<"该数据不再数组中"<<std::endl;
    }
}

template <class T>
void Array<T>::sort()
{
    T temp;
    std::cout<<"     "<<std::endl;
    for(int i=0;i<n-1;i++)
    {
        for(int j=n-1;j>i;j--)
        {
            if(sell[j]>sell[i])
            {
                temp=sell[i];
                sell[i]=sell[j];
                sell[j]=temp;
            }
        }
    }
}

template <class T>
void Array<T>::print()
{
    
    for(int i=0;i<n;i++)
    {
        std::cout<<"   "<<sell[i];
    }
    std::cout<<std::endl;
}

template <class T>
void Array<T>::sum()
{
    T sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+sell[i];
    }
    std::cout<<sum<<std::endl;
}


int main()
{
    int a[]={23,33,56,1,67,22};
    double b[]={11.1,22.2,33.3,1.1,4.4,9.9};

    Array<int> a1(a,6);
    Array<double> b1(b,6);

    a1.print();
    b1.print();

    a1.sort();
    b1.sort();

    a1.print();
    b1.print();
}