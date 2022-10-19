#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1

//测试程序长度定义
#define LONGTH 5

//类型定义
typedef int Status;
typedef int ElemType;

template <typename T>
class SqStack
{
private:
    T *elem;
    int top;
    int size;
    int increment;
public:
    SqStack(){}
    SqStack(int size,int inc)
    {
        this->elem=(T *)malloc(size*sizeof(T));
        if(NULL==this->elem) exit(0);
        this->top=0;
        this->size=size;
        this->increment=inc;
    }
    
    int getSize()
    {
        return this->size;
    }

    void printVec()
    {
        for(int j=0;j<this->top;j++)
        {
            std::cout<<"  "<<this->elem[j];
        }
        std::cout<<std::endl;
    }

    Status DestoryStack_Sq()
    {
        free(this->elem);
        this->elem=NULL;
        this->top=0;
        this->size=0;
        this->increment=0;
        return OK;
    }

    Status StackEmpty_Sq()
    {
        if(this->top==0) return TRUE;
        return FALSE;
    }

    void clearStack_Sq()
    {
        if(0==this->top) return;
        this->size=0;
        this->top=0;
    }

    Status Push_Sq(T e){
        T *newBase;
        if(this->top>=this->size)
        {
            newBase=(T *)realloc(this->elem,(size+increment)*sizeof(T));
            if(NULL==newBase) return OVERFLOW;
            this->elem=newBase;
            this->size=this->size+this->increment;
        }
        this->elem[this->top++]=e;
        return OK;
    }

    //
    T GetTop_Sq()
    {
        if(0==this->top) return ERROR;
        return this->elem[this->top-1];
    }

    T Pop_sq()
    {
        if(0==this->top) return ERROR;
        this->top--;
        return this->elem[this->top-1];
    }
};


int main()
{
    SqStack<double> q(10,10);
    std::vector<double> l={1,2,3,4,5,6,7,8,9,10};
    for(int i=0;i<l.size();i++)
    {
        q.Push_Sq(l[i]);
    }
    std::cout<<"size::"<<q.getSize()<<std::endl;
    q.printVec();

    std::vector<double> l2={1,2,3,4,5,6,7,8,9,10};
    for(int i=0;i<l2.size();i++)
    {
        q.Push_Sq(l2[i]);
    }
    std::cout<<"size::"<<q.getSize()<<std::endl;
    q.printVec();

    std::cout<<"Top::"<<q.GetTop_Sq()<<std::endl;
    q.printVec();

    std::cout<<"Pop Top::"<<q.Pop_sq()<<std::endl;
    q.printVec();
    
}

