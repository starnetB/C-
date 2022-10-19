#include<iostream>
#include<string.h>

using namespace std;
const int BUF=512;

class JustTesting
{
private:
    std::string words;
    int number;

public:
    JustTesting(const string& s="Just Testing",int n=0)
    {
        words=s;
        number=n;
        cout<<words<<"constructed"<<endl;
    }

    ~JustTesting()
    {
        cout<<words<<" destroyed"<<endl;
    }

    void show() const
    {
        cout<<words<<" ,"<<number<<endl;
    }
};


int main()
{
    char* buffer=new char[BUF];
    JustTesting *pc1,*pc2;
    pc1=new(buffer)JustTesting;
    pc2=new JustTesting("Heap1",20);

    std::cout<<"Memory block address"<<endl<<"buffer: "<<(void*)buffer<<"   heap:  "<<pc2<<endl;

    cout<<pc1<<": ";
    pc1->show();
    cout<<pc2<<": ";
    pc2->show();

    JustTesting *pc3,*pc4;
    //pc3 = new (buffer)JustTesting("Bad Idea", 6); //pc3直接占用了pc1的内存区域，这样一来如果pc1中有new分配的成员变量，将造成内存泄漏，
    //因此更好的方式是
    pc3=new (buffer+sizeof(JustTesting))JustTesting("Better Idea",6);
    pc4=new JustTesting("Heap2",10);

    cout<<"Memory Contents"<<endl;
    cout << pc3 << ": ";
    pc3->show();
    cout << pc4 << ": ";
    pc4->show();

    //由于delete buffer并不会出发buffer内对象的析构函数，所以只能手动调用其析构函数
    //需要注意调用析构函数的顺序，由于晚创建的对象可能依赖早创建的对象，因此析构的顺序应该与创建顺序相反，另外，仅当析构了所有对象之后，才能释放用于存储这些对象的缓冲区
    pc3->~JustTesting();
    pc1->~JustTesting();
    delete[] buffer;
    //delete pc1; 因为buffer和pc1实际上指向同一个地址，因此如果注释掉上面一行，打开这里，也可以正常运行，但逻辑上却是没有道理的
    //我们这边对定位new 析勾做个总结，
    //先手动调用西沟函数
    //然后在主动调用delete 删除对应的地址，这里是buffer，如果是右值，就不必要这样了
    cout << "done" << endl;
    cin.get();
    return 0;
}