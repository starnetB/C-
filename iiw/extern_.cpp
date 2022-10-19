#include <iostream>
using namespace std;

//表示变脸和函数是按照c语言方式编译和连接
#ifdef __cplusplus
extern "C" {
#endif

void pt();
#ifdef __cplusplus
}
#endif

void pt()
{
    cout<<"cccc"<<endl;
}

//struct 和 typedef struct student s

//C
typedef struct  Student
{
    int age;
} S;

struct  Strudent
{
    int age;
};

typedef struct Student S;

//C++ 一句话等价于上面
struct Student{
    int age;
};

struct t1{
    int a;
    int b;
};  //默认public

class t2{
    int a;
    int b;
};  //默认private

