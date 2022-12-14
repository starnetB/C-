
#include <iostream>
#include <vector>

int main()
{
    int a=0;  //a为非常量左值（有确定存储地址，也有变量名）（正确）
    const int a1=10; //常量左值(有确定存储地址，也有变量名) （正确）
    const int a2=10; //常量左值(有确定存储地址，也有变量名)  （正确）

    //先来大概总结下
    int &b=a;   //左值引用，可以引用带有存储空间，有确定存储地址的变量（正确）

    //下面这种引用是不可以的
    //int &b=10;  //左值引用是不可以直接引用临时变量，没有空间，在寄存器里面（错误）
    //int &c=a1;   //这种也不可以，因为a1是常量左值，但是使用非常量左值来使用的话，代表着引用对象可以被改变，这样的话明显是不对的（错误）
    //int &d=a1+a2 //这种也不可以，a1+a2 其实是return的一个常量右值，因此不可以被非常量左值（错误）
    
    const int &c1=a;       //非常左值,可以被常量左值引用绑定，但是引用别名是没法修改左值的量（正确）
    const int &c2=a1;      //常量左值，可以被常量左值引用绑定（正确）
    const int &c3=a+a1;    //非常量右值，可以被常量左值引用绑定（正确）
    const int &c5=a1+a2;   //常量右值，可以被常量左值引用绑定（正确）
    const int &c6=10;      //常量右值，可以被常量左值引用绑定（正确）

    //总结
    //非常左值引用，只能指向，非常左值，可以通过别名直接修改变量空间，
    //非常左值引用，不能指向，常左值，因为常量本身不能被修改的原因
    //常量左值引用，能指向一切
    //指向左值的时候就是正常开辟别名
    //指向右值的时候就是产生副本，然后在开辟别名，如下
    const int &c7=10;
    //等价于
    const int c8=10;
    const int &c9=c8;




    //以上虽然可以通过常量左值引用的方法，可以引用右值，但这样的话存在以下问题
    //1. 还是会产生副本
    //2. 通过常量引用的方法的话，会导致对象不可以被修改

    //因此C++11引入的右值引用，右值引用可以通过延长临时变量生命周期的方法，从而可以修改临时变量
    //临时变量，在旧内存部件(或者寄存器)中使用，这样的话可以少去拷贝构造等一系列方法，提升性能
    //非常量右值引用，只能指向非常量右值，因为常量右值不可以被改变，所以不能被非常量引用指向

    //右值引用举例
    int aa=0;  //a为非常量左值（有确定存储地址，也有变量名）（正确）
    const int aa1=10; //常量左值(有确定存储地址，也有变量名) （正确）
    const int aa2=10; //常量左值(有确定存储地址，也有变量名)  （正确）
    //非常量右值引用
    //int &&b1=aa;           //(错误)，右值引用指向左值是不可以的
    //int &&b2=aa1;          //(错误)，右值指向常量左值也是不可以的
    //int &&b3=10;          //(正确)，10是一个非常量右值，可以被非常量右值引用绑定
    //int &&b4=aa1+aa2        //（错误），（a1+a2)是一个常量右值，不可以被非常量右值引用指向
    //常量右值引用
    //const int &&c1=aa;      //错误，a是一个非常量左值，不可以被常量右值引用绑定
    //const int &&c2=aa1;     //错误,a1是一个常量左值，不可以被常量右值引用绑定
    const int &&cc3=aa+aa1;   //正确，（a+a1）是一个非常量右值，可以被常量右值引用绑定
    const int &&cc4=aa1+aa2;  //正确,（a1+a2）是一个常量右值，不可以被常量右值引用绑定
    //总结
    //1.右值只能引用右值
    //2.非常右值只能引用非常量右值
    //3.常量右值可以引用所有右值，但常量一侧没法修改

    
    int &&l=10;
    std::cout<<"右值引用测试1：："<<std::endl;
    std::cout<<l<<std::endl;  //我们可以看到，右值引用强行接管了临时变量10的空间，然后临时变量有了管理者，那么他就会像一个左值一样不会被销毁，然后生命周期就会延长
    

    /*
    //C++11中提供了一个标准库move函数获得绑定到左值上的右值引用，即直接调用std::move告诉编译器将左值像对待同类型右值一样处理，但是被调用后的左值将不能再被使用。 
    int a=10;                    ////非常量左值（有确定存储地址，也有变量名）
    const int a1=20;              //常量左值（有确定存储地址，也有变量名）

    int &&d1=std::move(a);      //正确，将非常量左值a转换为非常量右值，可以被非常量右值引用绑定
    //int &&d2=std::move(a1);    //错误,将常量左值a1转换为常量右值，不可以被非常量右值引用绑定

    //常量右值引用
    const int &&c1=std::move(a);      //正确，将非常量左值a转换为非常量右值，可以被常量右值引用绑定
    const int &&c2=std::move(a1);     //正确,将常量左值a1转换为常量右值，可以被常量右
    */
    

    //我们需要针对下面这句话作出解释和测试
    //即直接调用std::move告诉编译器将左值像对待同类型右值一样处理，但是被调用后的左值将不能再被使用。
    int j=10;                        //临时变量10,复制拷贝，给j，然后10被销毁
    int ii(std::move(j));             //设定j所在的空间作为右值，然后ii强行接管所在区域,产生拷贝，原始的10应该被销毁，但是由于10被简单变量直接j接管，所以本身还是不会被销毁
    int &&nn=std::move(j);            //nn和j指向原始对象，完全没有被释放的危险
    std::cout<<"move 测试1：："<<std::endl;
    ii=ii+1;
    std::cout<<ii<<std::endl;
    std::cout<<j<<std::endl;

    std::vector<int> vv{1,2,3,4,5,6};
    std::vector<int>&& v(std::move(vv));   //v和vv，会指向同一个区域，但vv只想的内容还是存在
    std::vector<int> v1(std::move(vv));  //调用这句后，会将vv里面的值给vv，然后将vv的直接地址还是存在，vv指向的内容当作右值是放掉  ，所以大型的复杂对象也是一样的
    std::cout<<"move 测试2"<<std::endl;
    for(int i=0;i<v.size();i++)
    {
        std::cout<<"------"<<std::endl;
        std::cout<<v[i]<<std::endl;
    }

    int *k=new int(10);
    int *o=std::move(k);
   
    //k=nullptr;
    std::cout<<"111111111111111111"<<std::endl;
    *k=*k+1;
    std::cout<<*o<<std::endl;
    std::cout<<*k<<std::endl;

    //std::move() 之后，临时变量左值没啥问题，但是设计指针的堆内存对象，在被复制后就会被释放

}   
