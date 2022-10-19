#include <iostream>

using namespace std;

int main()
{
    //简单引用
    /*
    int ival=1092;
    int &re=ival; //ok
    int &re2=ival;//ok
    //int &re3=&ival;  //错误
    int &re00=re2;  //引用传递是可以的
    */
    //指针引用
    /*
    int *pi=&ival;
    std::cout<<*pi<<std::endl;

    int *&pi2=pi;     //两个别名指向同一个区域，这个区域的地址是 pi pi2共同拥有的
    std::cout<<*pi2<<std::endl;*/
    //指针引用是个很奇葩的东西，一般很少使用
    int iv=100;
    //int *&pr=&iv;  //&iv相当于一个右值，直接使用指针引用去引用这个地址是不行的
    int *const &pr=&iv;  
    int *&&pr2=&iv;  //用右值引用 地址量好像也是可以的 ,
    std::cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<std::endl;
    std::cout<<*pr2<<std::endl;
    /*
    const int ival=1024;
    //const int *&pi_ref=&ival;  //const位置搞错了，重点强调指针本身的常量性质
    const int *const &pi_ref=&ival;  //正确
    const int *p=&ival;
    const int *&pi_ref=p;     //这样也行

    const int *p=&ival;  //这样直接用指针指向地址就可以了，所以指针引用了解下就可以了，
    */
    /*
    int *pi3=pi;
    std::cout<<*pi3<<std::endl;  //我看不懂指针引用的意义何在*/

    //const 引用的部分做法
    double dval=3.14159;
    const int &ir=1024;    //临时变量，引用右值
    int &&ir2=1024;
    std::cout<<ir<<std::endl;
    std::cout<<ir2<<std::endl;


    const int &ir3=dval;
    const int &ir6=4.88;
    //int &ir4=dval;       //左值引用不接受类型转换
    double &ir5=dval;
    const double &dr=dval+1.0;  //这个也等于右值引用
    std::cout<<ir3<<std::endl;
    std::cout<<ir5<<std::endl;
    std::cout<<ir6<<std::endl;  //
    std::cout<<dr<<std::endl;

    /*
    int vval=1024;
    const int &ir=vval;
    vval++;
    //ir++  ir不能被改变

    std::cout<<vval<<" "<<ir<<std::endl;*/
    return 0;

}