#include <iostream>

class testClass
{
public:
    testClass();                         /*默认构造函数*/
    testClass(int a,char b);             /*构造函数*/
    testClass(int a=10,char b='c');      /*默认构造函数*/
private:
    int m_a;
    char m_b;
};

//避免“无参数的默认构造函数”和“带缺省参数的默认构造函数”同时存在 
//无参数的默认构造函数和带缺省参数的默认构造函数同时存在时，编译器会产生二义性，从而生成编译错误
class Sample{
public:
    //默认构造函数
    Sample(){
        std::cout<<"Sample()"<<std::endl;
    }

    //默认勾召函数
    Sample(int m=10){
        std::cout<<"Sample(int m = 10)"<<std::endl;
    }
};

//由于Test1没有默认的构造函数，
//所以1 无法执行，故而编译错误。
//正确的代码如下，使用初始化列表代替赋值操作

//成员类型是没有默认构造函数的类。
//若没有提供显示初始化式，
//则编译器隐式使用成员类型的默认构造函数，
//若类没有默认构造函数，则编译器尝试使用默认构造函数将会失败。
class Test11
{
public:
    Test11(int a):i(a){}
private:
    int i;
};

class Test22
{
public:
    Test11 test11;
    Test22(Test11 &t11);
   // { test11=t11;}  //这里出现错误，因为test11，没有默认构造函数，所以会发生错误
};

class Test1
{
public:
    Test1(int a):i(a){}
    int i;
};

class Test2
{
    public:
        Test1 test1;
        Test2(int x):test1(x){}  //下面采用初始化列表进行初始化，可以在构造对象成员指向实现初始化，就不会有问题了
};

//const成员或者引用类型成员。因为const对象或者引用类型，通过初始化列表进行初始化，原因是，他们在声明时候必须产生对象，这个和上面本质上是一致的
//所以初始化列表，本质上是一种操作，针对，声明时的操作，在类内部成员声明时，同步完成的操作

using namespace std;

class A
{
public:
#if 0
    //因为成员变量中含有引用和常量则不能如此定义该构造函数
    //因为有些类型，必须在初始化声明的时候被构造好
    A(){
        std::cout<<"aaaaaaaaaaa"<<std::endl;
    }
#endif
#if 1
    A(int x1=0):x(x1),rx(x),pi(3.14){} //带有初始化列表的默认构造函数
    void print()
    {
        std::cout<<"x="<<x<<" rx="<<" pi="<<pi<<std::endl;

    }
    ~A(){}
private:
    int x;
    int &rx;
    const double pi;
#endif
};

//基类未声明默认构造函数
class Animal
{
public:
	Animal(int weight,int height):        //基类未声明默认构造函数
	m_weight(weight),m_height(height){
		cout<<"Animal "<<"weight="<<weight<<" height="<<height<<endl;
	}
 
private:
	int m_weight;
	int m_height;
};
 
class Dog: public Animal
{
public:
	Dog(int weight = 10,int height = 20,int type = 1):
	  Animal(weight,height){//必须使用初始化列表增加对父类的初始化,否则父类Animal无合适构造函数
		cout<<"Dog"<<endl;
	}
private:
	int m_type;
};