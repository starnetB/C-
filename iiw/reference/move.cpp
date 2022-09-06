#include <iostream>

//移动构造函数解决相关的问题

class HasPtrMem{
public:
    HasPtrMem():d(new int(3)),a(3){}   //普通构造函数
    HasPtrMem(const HasPtrMem& h):d(new int(*h.d)){} //copy构造函数
    HasPtrMem(HasPtrMem && h):d(h.d),a(h.a){
        std::cout<<"-------------"<<std::endl;
        *h.d+=1;
        h.a+=1;
        std::cout<<*h.d<<std::endl;
        std::cout<<h.a<<std::endl;
        std::cout<<*this->d<<std::endl;
        std::cout<<this->a<<std::endl;
        h.d=nullptr;
        
    }  //转移构造函数:
    int *d;
    int a;
};

HasPtrMem getTemp(){
    HasPtrMem h;
    std::cout<<"=========="<<std::endl;
    return h;
}

int main()
{
    HasPtrMem a(std::move(getTemp()));
}


