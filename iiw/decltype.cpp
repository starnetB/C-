#include <iostream>

// 尾置返回允许我们在参数列表之后声明返回类型
// 也就是->后面的内容，指定返回的类型
template <typename It>
auto fcn(It beg,It end)->decltype(*beg)  //decltype (×beg) 为解引用操作，放回类型的引用
{
    return *beg;
}

template <typename It>
auto fcn2(It beg,It end)->typename std::remove_reference<decltype(*beg)>::type  //去掉引用，返回类型本身
{
    return *beg;
}

//delctype的常规使用
// 有时我们希望从表达式的类型推断出要定义的变量类型，但是不想用该表达式的值初始化变量（初始化可以用auto）。为了满足这一需求，C++11新标准引入了decltype类型说明符，它的作用是选择并返回操作数的数据类型，在此过程中，编译器分析表达式并得到它的类型，却不实际计算表达式的值。

//decltype用法
int getSize();

int main(void)
{
    int tempA=2;

    // 普通类型，返回类型本身
    decltype(tempA) declTempA;

    //*2.dclTempB为int，对于getSize根本没有定义，但是程序依旧正常，因为decltype只做分析，并不调用getSize().*/
    decltype(getSize()) dclTempB;


    //下面decltype与const相互结合
    double tempA=3.0;
    const double ctempA=5.0;
    const double ctempB=6.0;
    const double *const cptrTempA=&ctempA;  //这里前面一个const是指常量指针，指针所表示的对象是常量，
    //后面一个const是指 指针本身常量，表示指针本身的地址不能被修改

    /*1.dclTempA推断为const double（保留顶层const，此处与auto不同）*/
    decltype(ctempA) dclTempA=4.1;
    /*2.dclTempA为const double，不能对其赋值，编译不过*/
    //dclTempA = 5;

    /*3.dclTempB推断为const double * const*/
    decltype(cptrTempA) dclTempB = &ctempA;
    /*4.输出为4（32位计算机）和5*/
    //cout<<sizeof(dclTempB)<<"    "<<*dclTempB<<endl;
    /*5.保留底层const，不能修改指针指向的对象，编译不过*/
    //dclTempB = &ctempB;
    /*6.保留顶层const，不能修改指针指向的对象的值，编译不过*/
    //*dclTempB = 7.0;

    //int tempA = 0, &refTempA = tempA;

    /*1.dclTempA为引用，绑定到tempA*/
    //decltype(refTempA) dclTempA = tempA;
    /*2.dclTempB为引用，必须绑定到变量，编译不过*/
    //decltype(refTempA) dclTempB = 0;
    /*3.dclTempC为引用，必须初始化，编译不过*/
    //decltype(refTempA) dclTempC;
    /*4.双层括号表示引用，dclTempD为引用，绑定到tempA*/
    //decltype((tempA)) dclTempD = tempA;
    
    //const int ctempA = 1, &crefTempA = ctempA;
    
    /*5.dclTempE为常量引用，可以绑定到普通变量tempA*/
    //decltype(crefTempA) dclTempE = tempA;
    /*6.dclTempF为常量引用，可以绑定到常量ctempA*/
    //decltype(crefTempA) dclTempF = ctempA;
    /*7.dclTempG为常量引用，绑定到一个临时变量*/
    //decltype(crefTempA) dclTempG = 0;
    /*8.dclTempH为常量引用，必须初始化，编译不过*/
    //decltype(crefTempA) dclTempH;
    /*9.双层括号表示引用,dclTempI为常量引用，可以绑定到普通变量tempA*/
    //decltype((ctempA))  dclTempI = ctempA;

    //int tempA = 2;
    //int *ptrTempA = &tempA;
    /*1.常规使用dclTempA为一个int *的指针*/
    //decltype(ptrTempA) dclTempA;
    /*2.需要特别注意，表达式内容为解引用操作，dclTempB为一个引用，引用必须初始化，故编译不过*/
    //decltype(*ptrTempA) dclTempB;
    return 0;
}


//总结
// 对待普通变量，返回原有类型，这个auto和decltype是一样的
// 对待指针，返回指针本身这个也是一样的 auto和decltype
// const 引用 和解引用就 auto和decltype就很不一样 ，
// auto 除了底层的const 去不掉之外，const 和atuo 解引用全部去掉，返回原有类型
// decltype 全部保留，引用和解引用 也会保留引用本身，const就不用说了全部保留

