//循环队列

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

template <typename T>
class Node
{
    //False 表示点已经被删除
    //True 表示点还存在
public:
    
    bool status_;
    T val_;
    Node(){}
    //Node(bool status,int val):status_(status),val_(val){}

    void set(bool status,T val)
    {
        this->status_=status;
        this->val_=val;
    }

    bool getStatus()
    {
        return this->status_;
    }
};

template <typename T>
class cirSq
{
private:
    Node<T> *elem;
    int front;
    int rear;
    int maxSize;

public:
    cirSq(int maxsize=10)
    {
        this->elem=new Node<T>[maxsize];

        if(NULL==this->elem)
        {
            std::cout<<"Failed to Alloc memory!"<<std::endl;
            exit(0);
        }
        for(int k=0;k<maxsize;k++)
        {
            this->elem[k].set(false,0);
        }

        this->front=0;
        this->rear=0;
        this->maxSize=maxsize;
    }

    ~cirSq(){
        if (this->elem!=NULL)
        {
            delete[] this->elem;
            this->elem=NULL;
        }
    }

    int getSize();   //打印循环链表的大小
    int getNum();     //获取循环链表中的数据个数
    void printALl(); //打印循环链表中的所有内容

    void push_csq(T e);  //在循环链表尾部插入数据
    T pop_csq();   //弹出头部数据
    T get_Front();    //获取头部数据
    void E_csq(int maxSize); //扩展队列大小

    //判断链表是否已经满了
    bool _FULL();
    //判断链表是否是空的
    bool _EMPTY();
};

template <typename T>
bool cirSq<T>::_FULL()
{
    int count=0;
    for(size_t i=0;i<this->maxSize;i++)
    {
        if(this->elem[i].getStatus())
        {
            count++;
        }
    }
    if(count>=this->maxSize)
        return true;
    else
        return false;
}

template <typename T>
bool cirSq<T>::_EMPTY()
{
    int count=0;
    for(size_t i=0;i<this->maxSize;i++)
    {
        if(this->elem[i].getStatus())
        {
            count++;
        }
    }
    if(count<=0)
        return true;
    else
        return false;
}

template <typename T>
int cirSq<T>::getSize()
{
    return this->maxSize;
}

template <typename T>
int cirSq<T>::getNum()
{
    int count=0;
    for(size_t i=0;i<this->maxSize;i++)
    {
        if(this->elem[i].getStatus())
        {
            count++;
        }
    }
    return count;
}

template <typename T>
void cirSq<T>::printALl()
{
    for(size_t i=0;i<this->maxSize;i++)
    {
        if(this->elem[i].getStatus())
        {
            std::cout<<"  "<<this->elem[i].val_;
        }
    }
    std::cout<<std::endl;
}


template <typename T>
void cirSq<T>::push_csq(T e)
{
    if(this->_FULL())
    {
        std::cout<<"Data is FuLL!"<<std::endl;
        return;
    }
    std::cout<<this->rear<<std::endl;
    this->elem[this->rear].set(true,e);
    this->rear++;

    if(this->front>=this->maxSize)
        this->front-=this->maxSize;
    if(this->rear>=this->maxSize)
        this->rear-=this->maxSize;
}

template <typename T>
T cirSq<T>::get_Front()
{
    int result=-999;
    if(this->_EMPTY())
    {
        std::cout<<"NO Data can be find!"<<std::endl;
        return static_cast<T>(result);
    }
    return this->elem[this->front].val_;
    
}

template <typename T>
T cirSq<T>::pop_csq()
{
  

    if(this->_EMPTY())
    {
        std::cout<<"NO Data can be find!"<<std::endl;
        int result=-999;
        return static_cast<T>(result);
    }
    this->elem[this->front].status_=false;
    T result=this->elem[this->front].val_;
    this->front++;
    
    if(this->front>=this->maxSize)
        this->front-=this->maxSize;
    if(this->rear>=this->maxSize)
        this->rear-=this->maxSize;
    
    return result;
}


template <typename T>
void cirSq<T>::E_csq(int inc)
{
    int newMaxSize=this->maxSize+inc;
    Node<T> *tmp=new Node<T>[newMaxSize];

    for(int i=0;i<newMaxSize;i++)
    {
        tmp[i].set(false,0);
    }
    for(int i=0;i<this->maxSize;i++)
    {
        tmp[i].status_=this->elem[i].status_;
        tmp[i].val_=this->elem[i].val_;
    }
    delete[] this->elem;
    this->rear=this->maxSize;
    this->elem=tmp;
    this->maxSize=newMaxSize;
}


int main()
{
    cirSq<double> sq(20);
    sq.printALl();
    std::vector<double> l={1,2,3,4,5,6,7,8,9,10,
                           11,12,13,14,15,16,17,18,19,20,21};
    for(int i=0;i<l.size();i++)
    {
        sq.push_csq(l[i]);
    }
    sq.printALl();
    std::cout<<sq.getNum()<<" "<<sq.getSize()<<std::endl;

    std::cout<<sq.get_Front()<<std::endl;
    sq.printALl();
    std::cout<<sq.getNum()<<" "<<sq.getSize()<<std::endl;

    std::cout<<sq.pop_csq()<<std::endl;
    std::cout<<sq.pop_csq()<<std::endl;
    // std::cout<<sq.pop_csq()<<std::endl;
    // std::cout<<sq.pop_csq()<<std::endl;
    // std::cout<<sq.pop_csq()<<std::endl;
    // std::cout<<sq.pop_csq()<<std::endl;
    // std::cout<<sq.pop_csq()<<std::endl;
    // std::cout<<sq.pop_csq()<<std::endl;
    // std::cout<<sq.pop_csq()<<std::endl;
    // std::cout<<sq.pop_csq()<<std::endl;
    // std::cout<<sq.pop_csq()<<std::endl;
    // std::cout<<sq.pop_csq()<<std::endl;
    // std::cout<<sq.pop_csq()<<std::endl;
    // std::cout<<sq.pop_csq()<<std::endl;
    // std::cout<<sq.pop_csq()<<std::endl;
    // std::cout<<sq.pop_csq()<<std::endl;
    // std::cout<<sq.pop_csq()<<std::endl;
    // std::cout<<sq.pop_csq()<<std::endl;
    // std::cout<<sq.pop_csq()<<std::endl;
    // std::cout<<sq.pop_csq()<<std::endl;
    // std::cout<<sq.pop_csq()<<std::endl;
    // std::cout<<sq.pop_csq()<<std::endl;
    // std::cout<<sq.pop_csq()<<std::endl;
    // std::cout<<sq.pop_csq()<<std::endl;
    sq.printALl();
    std::cout<<sq.getNum()<<" "<<sq.getSize()<<std::endl;
    
    sq.push_csq(21);
    sq.push_csq(22);
    sq.printALl();
    std::cout<<sq.getNum()<<" "<<sq.getSize()<<std::endl;

    sq.E_csq(5);
    sq.printALl();
    std::cout<<sq.getNum()<<" "<<sq.getSize()<<std::endl;

    sq.push_csq(24);
    sq.push_csq(25);
    sq.push_csq(26);
    sq.push_csq(27);
    sq.push_csq(28);
    sq.push_csq(29);
    
    std::cout<<"====================="<<std::endl;
    sq.printALl();
    std::cout<<sq.getNum()<<" "<<sq.getSize()<<std::endl;

}