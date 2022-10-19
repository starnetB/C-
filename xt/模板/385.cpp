#include <iostream>

template <typename T>
class A
{
private:
    T a;
public:
    A(T a1)
    {
        a=a1;
    }

    void operator++();

    void print()
    {
        std::cout<<a<<std::endl;
    }
};

template<class T>
void A<T>::operator++()
{
    a++;
}




int main()
{
    A<char> a1('a');
    ++a1;
    a1.print();

    A<int> a2(33);
    ++a2;
    a2.print();
}