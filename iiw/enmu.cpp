#include <iostream>


//限定作用域的枚举
enum class open_modes {
    input ,output,append
};

class A {
public:
    enum state {input ,output,append};
};

//不限定作用域的枚举类型
enum color {red,yellow,green};
enum {floatPrec =6,doublePrec=10};

int main(int argv,char **argc)
{
    std::cout<<int(open_modes::input)<<std::endl;
    std::cout<<int(A::input)<<std::endl;

    color c;
    c=yellow;
    std::cout<<c<<std::endl;
    std::cout<<red<<std::endl;
    std::cout<<floatPrec<<std::endl;
}