//explicit 总结，这个听复杂的
//explicit 修饰构造函数时，可以防止隐式转换和复制初始化
// 构造函数隐士调用，
// 会给函数重载，操作符重载，多类型勾召函数一致等情况下，
// 产生冲突与错误，从而导致一些问题
// 复制初始化，会产生不必要的对象，同时可能会和等号重载产生冲突

//explicit 修饰转换函数时，可以防止隐式转换，但 按语境转换 除外
// 产生的错误
// 如：操作符号重载  +号等，到底调用操作符号重载呢，还是调用隐士转换
// 按语境转换，往往是括号内的转换就是按语境转换
// 按语境转换有那些情况
// if、while、for 的控制表达式；
// 内建逻辑运算符 !、&& 和 || 的操作数；
// 条件运算符 ?: 的首个操作数；
// static_assert 声明中的谓词；
// noexcept 说明符中的表达式；
// explicit 说明符中的表达式。
//(C++20 起)

struct  A
{
    A(int) {}
    operator bool() const {return true;}
};

struct B
{
    explicit B(int){}
    explicit operator bool() const {return true;}
};

void doA(A a){}

void doB(B b){}

int main()
{
    A a1(1);		// OK：直接初始化
	A a2 = 1;		// OK：复制初始化
	A a3{ 1 };		// OK：直接列表初始化
	A a4 = { 1 };		// OK：复制列表初始化
	A a5 = (A)1;		// OK：允许 static_cast 的显式转换 
	doA(1);			// OK：允许从 int 到 A 的隐式转换
	if (a1);		// OK：使用转换函数 A::operator bool() 的从 A 到 bool 的隐式转换
	bool a6(a1);		// OK：使用转换函数 A::operator bool() 的从 A 到 bool 的隐式转换
	bool a7 = a1;		// OK：使用转换函数 A::operator bool() 的从 A 到 bool 的隐式转换
	bool a8 = static_cast<bool>(a1);  // OK ：static_cast 进行直接初始化

    B b1(1);		// OK：直接初始化
	//B b2 = 1;		// 错误：被 explicit 修饰构造函数的对象不可以复制初始化
	B b3{ 1 };		// OK：直接列表初始化
	//B b4 ={ 1 };		// 错误：被 explicit 修饰构造函数的对象不可以复制列表初始化
	B b5 = (B)1;		// OK：允许 static_cast 的显式转换
	//doB(1);			// 错误：被 explicit 修饰构造函数的对象不可以从 int 到 B 的隐式转换

    if (b1);		// OK：被 explicit 修饰转换函数 B::operator bool() 的对象可以从 B 到 bool 的按语境转换
	bool b6(b1);		// OK：被 explicit 修饰转换函数 B::operator bool() 的对象可以从 B 到 bool 的按语境转换

    //bool b7 = b1;		// 错误：被 explicit 修饰转换函数 B::operator bool() 的对象不可以隐式转换
	bool b8 = static_cast<bool>(b1);  // OK：static_cast 进行直接初始化
    //上面这个有点像显示转换
    return 0;
}
