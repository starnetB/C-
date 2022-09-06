#include <iostream>

//参数多态性
//其实就是通过模板实现多态

template <class T>
T max(T a,T b){
    return a>b?a:b;
}

// int main()
// {
//     std::cout<<::max(9,5)<<std::endl;

//     std::string foo("foo"),bar("bar");
//     std::cout<<::max(foo,bar)<<std::endl;
// }

//强制转换多态性(转换)

//static_cast
//const_cast
//reinterpret_cast
//dynamic_cast
//等先对对象进行显式转换，然后进行多态操作
//explicit的使用可以防止隐转换式