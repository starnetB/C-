
#include <iostream>

class SqStack{
private:
    int *elem;
    int top;
    int size;
    int delta_add;

public:
    SqStack(){}

    //初始化顺序表
    void initSqStack(const int &size,const int& delta){
        this->size=size;
        this->delta_add=delta;
        this->top=0;

        elem=new int[this->size];

        if(!elem)
        {
            std::cout<<"分配内存失败"<<std::endl;
            exit(-1);
        }
    }

    //销毁顺序表
    void DestoryStack_Sq()
    {
        delete[] this->elem;
        this->elem=NULL;
    }

    //清空顺序表
    void ClearStack_Sq()
    {
        for(int i=0;i<this->size;i++)
        {
            this->elem[i]=0;
        }
        this->top=0;
        this->size=0;
    }

    //若循序表为空，则返回TRUE，否则返回FALSE
    bool IsEmpty()
    {
        if(this->top==0) return true;
        return false;
    }

    //返回顺序表中元素的个数
    int ElemNumber()
    {
        return this->top+1;
    }

    //返回顺序表L中第i个元素的值
    int GetElem(int index)
    {
        return this->elem[index];
    }

    //元素e压入栈S
    bool Push_Sq(int node)
    {
        
        if(this->top>=this->size)
        {
            delete[] this->elem;
            int *newbase=new int[size+delta_add];
            if(newbase==NULL)
            {
                std::cout<<"Failed to Extend memory!"<<std::endl;
                return false;
            }
            this->elem=newbase;
            this->size=size+delta_add;
        }
        this->elem[top++]=node;
        return true;
    }

    //出栈
    int Pop_Sq()
    {
        if(this->top==0) return -99999;
        auto e=elem[top-1];
        top--;
        return e;
    }

    void print_Sq()
    {
        for(int i=0;i<top;i++)
        {
            std::cout<<"  "<<elem[i]<<std::endl;
        }
        std::cout<<std::endl;
    }
};


int main()
{
    SqStack s_q;
    s_q.initSqStack(10,5);

    for(int i=0;i<10;i++)
    {
        s_q.Push_Sq(i);
    }

    s_q.print_Sq();

    std::cout<<s_q.Pop_Sq()<<std::endl;
    std::cout<<s_q.Pop_Sq()<<std::endl;

    s_q.print_Sq();

    s_q.ClearStack_Sq();
    s_q.print_Sq();

    s_q.DestoryStack_Sq();
}




//打印顺序表中的值

//给顺序表赋值，第i个元素赋值

//在顺序表的表尾添加元素e

//删除顺序表L的表尾元素，并用参数e返回其值