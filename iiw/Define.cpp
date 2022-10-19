#include <iostream>
//#define  标识符  字符串
#define MAXNUM 9999
//#define  宏名(形参表)  字符串
#define add(x, y) (x + y)

//使用# 将变量名字转化为字符串
#define PSQR(x) printf("the square of" #x "is %d.\n",(x)*(x))

//##运算符可以用于类函数宏的替换部分。另外，##还可以用于类对象宏的替换部分。这个运算符把两个语言符号组合成单个语言符号。
#define XNAME(n) x##n
#define PXN(n) printf("x"#n" = %d\n",x##n)

//可变参数宏 …和__VA_ARGS__
#define PR(...) printf(__VA_ARGS__)
int main()
{
    std::cout<<MAXNUM<<std::endl;
    std::cout << "1 plus 1 is " << add(1, 1.5) << ".\n";

    int y =4;
    PSQR(y);
    //输出：the square of y is 16.
    PSQR(2+4);
    //输出：the square of 2+4 is 36.

    int wt=1,sp=2;
    PR("hello\n");
    //输出：hello
    PR("weight = %d, shipping = %d",wt,sp);
    //输出：weight = 1, shipping = 2
}