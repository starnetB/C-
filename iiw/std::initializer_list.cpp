#include <iostream>
#include <vector>

//初始化器列表初始化一个对象
#include <initializer_list>


template<class T>
struct S
{
    /* data */
    std::vector<T> v;
    S(std::initializer_list<T> l):v(l)
    {
        std::cout<<"contructed with a "<<l.size()<<"-element list \n";
    }

    void append(std::initializer_list<T> l){
        v.insert(v.end(),l.begin(),l.end());
    }

    std::pair<const T*,std::size_t> c_arr() const {
        return {&v[0],v.size()};
    }
};

template <typename T>
void templated_fn(T) {}

int main()
{
    S<int> s={1,2,3,4,5}; //复制初始化
    s.append({6,7,8});

    std::cout<<"The vector size is now "<<s.c_arr().second<<"ints:\n";

    for(auto n:s.v)
        std::cout<<n<<' ';

    std::cout<<'\n';
    std::cout<< "Range -for over brace-init-list:\n";

    for(int x:{-1,-2,-3})
        std::cout<<x<<" ";
    
    std::cout<<'\n';

    auto al={10,11,12};  //auto 自带特殊规则
    std::cout<<"The list bound to auto has size() ="<<al.size()<<'\n';

   // templated_fn({1,2,3});//// 编译错误！“ {1, 2, 3} ”不是表达式，
                             // 它无类型，故 T 无法推导
    templated_fn<std::initializer_list<int>>({1,2,3}); //OK
    templated_fn<std::vector<int>>({1,2,3}); //也OK
}
