#include <iostream>


class Complex
{
    int r;
    int i;
public:
    Complex(){}
    Complex(int r, int i)
    {
        this->r=r;
        this->i=i;
    }

    void disp()
    {
        std::cout<<r<<"+"<<i<<"i"<<std::endl;
    }

    Complex operator+(Complex c2)
    {
        int a=this->r+c2.r;
        int b=this->i+c2.i;
        Complex c3(a,b);
        return c3;
    }

    Complex operator-(Complex c2)
    {
        int a=this->r-c2.r;
        int b=this->i-c2.i;
        Complex c3(a,b);
        return c3;
    }
};

int main()
{
    Complex c1(10,10);
    Complex c2(10,10);
    Complex &&c3=c1+c2;
    c3.disp();
}