#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct Node
{
    T val;
    Node *next;
    Node(){}
    Node(T val_):val(val_){
        next=NULL;
    }
};

template <typename T>
class Sequence
{
private:
    T *elem;
    int front;
    int rear;
    int maxSize;
    enum SeqStatus{SUCCESS,NOUSE,FAILED}; 
public:
    explicit Sequence()
    {
        this->elem=(T *)malloc(sizeof(T));
        if(NULL==this->elem)
        {   
            std::cout<<"Failed to alloc Memeroy!"<<std::endl;
            exit(0);
        }
        this->front=0;
        this->rear=0;
        this->maxSize=0;
    }

    ~Sequence()
    {
        destroySeq();
    }

    SeqStatus destroySeq()
    {
        free(this->elem);
        this->front=0;
        this->rear=0;
        this->maxSize=0;
        return SUCCESS;
    }

    T getFront()
    {
        if(this->front==this->rear)
        {
            std::cout<<"No Data in Sequeque!"<<std::endl;
            exit(0);
        }
        return this->elem[this->front];
    }
    
    T push_Seq(T e)
    {
        if (this->rear>=this->maxSize)
        {
            T *tmp=(T *)realloc(this->elem,(this->maxSize+1)*sizeof(T));
            if(NULL==tmp)
            {
                std::cout<<"Failed to alloc Memeroy!"<<std::endl;
                exit(0);
            }
            this->elem=tmp;
            this->maxSize++;
        }
        this->elem[this->rear++]=e;
        return e;
    }

    T pop_Seq()
    {
        if(this->front==this->rear)
        {
            std::cout<<"No Data in Sequeque!"<<std::endl;
            exit(0);
        }
        T result=this->elem[this->front];
        for(int k=0;k<this->rear;k++)
        {
            this->elem[k]=this->elem[k+1];
        }
        this->rear--;
        return result;
    }

    void print()
    {
        for(int i=0;i<this->rear;i++)
        {
            std::cout<<" "<<this->elem[i];
        }
        std::cout<<std::endl;
    }
};

int main()
{
    Sequence<int> sq;
    std::vector<double> l={1,2,3,4,5,6,7,8,9,10};
    for(int i=0;i<l.size();i++)
    {
        sq.push_Seq(l[i]);
    }
    sq.print();

    std::cout<<sq.getFront()<<std::endl;
    sq.print();

    std::cout<<sq.pop_Seq()<<" "<<sq.pop_Seq()<<" "<<sq.pop_Seq()<<std::endl;
    sq.print();

}