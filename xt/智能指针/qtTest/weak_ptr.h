#ifndef WEAK_PTR_H
#define WEAK_PTR_H
#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>

using namespace std;
class Controller
{
public:
    int Num;
    wstring Status;
    vector<weak_ptr<Controller>> others;

    explicit Controller(int i):Num(i),Status(L"On")
    {
        wcout<<L"Creating Controller"<<Num<<std::endl;
    }
    ~Controller()
    {
        wcout<<L"Destroying Controller"<<Num<<std::endl;
    }

    // Demonstrates how to test whether the
    // pointed-to memory still exists or not.
    void CheckStatus() const
    {
        for_each(others.begin(), others.end(), [](weak_ptr<Controller> wp) {
            auto p=wp.lock();
            if(p)
            {
                wcout<<L"Status of "<<p->Num<<" = "<<p->Status<<std::endl;
            }
            else
            {
                wcout<<L"NULL obje"<<std::endl;
            }
        });
    }
};

void RunTest()
{
    vector<shared_ptr<Controller>> v
    {
        make_shared<Controller>(0),
        make_shared<Controller>(1),
        make_shared<Controller>(2),
        make_shared<Controller>(3),
        make_shared<Controller>(4),
    };

    // Each controller depends on all others not being deleted.
    // Give each controller a pointer to all the others.
    for (size_t i = 0; i < v.size(); ++i)
    {
      for_each(v.begin(), v.end(), [&v, i](shared_ptr<Controller> p) {
         if (p->Num!= int(i))
         {
            v[i]->others.push_back(weak_ptr<Controller>(p));
            wcout << L"push_back to v[" << i << "]: " << p->Num << endl;
         }
      });
    }

    for_each(v.begin(), v.end(), [](shared_ptr<Controller> &p) {
      wcout << L"use_count = " << p.use_count() << endl;
      p->CheckStatus();
   });
}

class A;

class B
{
public:
    ~B()
    {
     std::cout<<"B destory,a_ptr use_cout:"<<a_ptr.use_count()<< "\n";
    }

    //std::shared_ptr<A> a_ptr;//它会造成循环引用
    std::weak_ptr<A> a_ptr;
};

class A
{
public:
    ~A()
    {
        std::cout<<"A destory ,b_ptr use_count:"<<b_ptr.use_count()<<"\n";
    }

    // std::shared_ptr<B> b_ptr;//它会造成循环引用
    std::weak_ptr<B> b_ptr;//它不会循环引用
};


#endif // WEAK_PTR_H
