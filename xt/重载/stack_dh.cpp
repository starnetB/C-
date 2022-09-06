#include <iostream>

class Stack
{
    int *sp;
    int top;
    int max;
    static int count;
public:
    Stack(int size=10)
    {
        sp=new int[10];
        max=size;
        top=0;
    }

    ~Stack(){
        if(sp!=NULL)
        {
            std::cout<<count<<std::endl;
            count++;   
            delete[] sp;
            std::cout<<"=========="<<std::endl;
            sp=NULL;
        }
    }
    //容量扩展
    void inflate();

    void push(int value){
        if(top==max)
            inflate();
        sp[top++]=value;
        
    };

    int pop()
    {
        if(top<=0)
            return -1;
        else
            return sp[--top];
    }

    //等号运算函数
    Stack& operator=(Stack &s1);

private:
    //explicit Stack(const Stack& s2);
};

// Stack::Stack(const Stack& s2)
// {
//     this->max=s2.max;
//     this->top=s2.top;
//     std::cout<<"aaa"<<std::endl;
// }
int Stack::count=0;

Stack& Stack::operator=(Stack &s)
{
    this->top=s.top;
    this->max=s.max;
 
    for(int i=0;i<top;i++)
    {
        this->sp[i]=s.sp[i];
    }
    return *this;
}


void Stack::inflate()
{
    int *tp=new int[max*2];
    for (int i=0;i<top;i++)
    {
        tp[i]=sp[i];
    }

    max+=max;
    delete[] sp;
    sp=tp;
}

int main()
{
    Stack s1(10);
    Stack s2,s3;
    s3=s2=s1;
}