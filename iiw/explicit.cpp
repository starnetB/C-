//我们首先得了解隐式转换的类型
// explicit 修饰构造函数时，可以防止隐式转换和复制初始化
#include <iostream>

class int_proxy{
public:
    int_proxy(int n):_m(n){}
public:
    int value() const {
        return _m;
    }
private:
    int _m;
};

class int_proxy{
public:
    int_proxy(int n):_m(n){}
public:
    int value() const {
        return _m;
    }
private:
    int _m;
};



void test_int_proxy(const int_proxy& v)
{
    std::cout<<v.value()<<std::endl;
}

//重载错误
void test_int_proxy(const int& v)
{
    std::cout<<v<<std::endl;
}

//防止构造函数偷偷的调用复制初始化，如下面第二种情况
//复制初始化会多出很多副本，尽量少用
//而且与等号重载也会有冲突
//1、ClassTest ct1("ab");这条语句属于直接初始化，它不需要调用复制构造函数，直接调用构造函数ClassTest(const char *pc)，所以当复制构造函数变为私有时，它还是能直接执行的。

//2、ClassTest ct2 = "ab";这条语句为复制初始化，它首先调用构造函数ClassTest(const char *pc)函数创建一个临时对象，然后调用复制构造函数，把这个临时对象作为参数，构造对象ct2；所以当复制构造函数变为私有时，该语句不能编译通过。

//为了防止后台的隐士转换和复制初始化，我们可以调用explicit 来防止在构造函数构造对象时产生隐士转换和调用复制初始化

// explicit 修饰转换函数
// 什么转换函数
class Fraction
{
public:
    Fraction(int numerator,int denominator=1):m_numerator(numerator)
    {}
    //转换函数
    operator double() const{
        return (double)m_numerator/m_denominator;
    }

private:
    int m_numerator;
    int m_denominator;
};

class integer
{
public:
    integer(int i=0);
    operator int() const;
    friend integer operator + (const integer& i,const integer& i2);
private:
    int m_ivalue;
};

int main()
{
    // 正常，没有隐式转换
    test_int_proxy(int_proxy(100));

    // 不正常，含有隐式转换
    test_int_proxy(100); //找不到对象时，会去找int_proxy中，含有相同参数类型的构造函数

    //隐士转换可能出出现的问题1
    //test_int_proxy(100);  //这里你很难确定去调用那个test函数了

    //错误2：很难确定调用test_int_proxy,test_int_proxy2

    //隐士转换可能出现的问题三
    integer A1,A2;
    integer A3 = A1 + A2;
    //int i = A3+1;  //该如何做？是把A3转化成int做+运算？还是把1转换成Integer做operator+运算？
                   //该如何做？是把A3转化成int做+运算？还是把1转换成Integer做operator+运算？
    //为了解决上面的问题，可以把integer的构造函数前面加上explicit 防止构造函数的隐士转换，也可以在转换函数前面加上explicit，防止转换函数的隐士转换
    
    //explicit 可防止隐士转换，但不可以防止转换函数的按语境转换
    //什么按语境转换，就是括号内的语境和转换函数的类型是一致的，那么这是explicit是失效的
    //如果int a=A，这时候转换函数不可以隐士调用，变成int，必须显示调用
    //int a=(int)A

    //转换函数的使用方法
    Fraction f(3,5);
    //首先，它会寻找+操作符是否有重载了参数为double和Fraction的函数。很明显，我们并没有为刚刚新建的类Fraction重载+操作符，编译器的该次尝试以失败告终。

    //接着，不轻言放弃的编译器发现操作符+可以接收两个double类型的参数，那么是否可以将Fraction转换为double，从而调用该版本的函数呢？这次编译器成功了，因为我们刚刚实现了转换为double的函数。
    double sum=4+f;  
}

