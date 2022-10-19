#include <stdio.h>
#include <iostream>
#include <vector>

typedef int KeyType;

struct RcdType
{
    KeyType key;
};

template<class T>
class HashTable
{

public:
    explicit HashTable(){}

    explicit HashTable(int size_,std::initializer_list<T> l):
        size(size_),hashsize(l),index(0){
    }
    
    explicit HashTable(const HashTable& ht)
    {
        delete[] rcd;
        rcd=NULL;
        delete[] tag;
        tag=NULL;

        this->size=ht.size;
        this->tag=ht.tag;
        this->rcd=ht.tcd;

    }

    ~HashTable()
    {
        delete[] this->tag;
        delete[] this->rcd;
        this->tag=NULL;
        this->rcd=NULL;
    }

    //初始化hash表，并且指控
    bool initHashTable(int size)
    {
        this->rcd=new RcdType[size];
        this->tag=new int[size];
        if(this->rcd==NULL||this->tag==NULL)
        {
            return false;
        }
        for(int i=0;i<size;i++)
        {
            this->rcd[i].key=9999;
            this->tag=0;
        }
        this->size=size;
        this->count=0;
        return true;
    }

    int Hash(KeyType key,int m)
    {
        return (3*key)%m;
    }

    int collision(int &p,int m)
    {
        p=(p+1)%m;
    }

    bool SearchHash(keyType key,int &p,int &c)
    {
        p=Hash(key,H.size); //找到一个Hash位置
        int h=p;
        c=0;  //获取冲突数量
        // 两种情况，
        //一种是当前位置，已经被其他数据占用
        //另一种是当前位置，当前位置已经被删除
        //重新检测新位置
        while((1==this->tag[p]&&this->rcd[p].key!=key) || -1==this->tag[p])
        {
            collision(p,this->size);
        }

        //key已经被找到了
        if(1==this->tag[p] && key==this->rcd[p].key)
        {
            return  true;
        }
        //当前位置是空的，可以被插入
        else return false;
    }

    bool recreateHash()
    {
        HashTable H
        RcdType *orcd;
        int *otag,osize,t;
        orcd=this->rcd;
        otag=this->tag;
        osize=this->size;
      

        H.initHashTable(hashsize[this->index++])
        for(int i=0;i<osize;i++)
        {
            if(1==otag[i])
            {
                H.InsertHash(orcd[i].key);
            }
        }
        this=H;
        return true;
    }

    bool InsertHash(KeyType key)
    {
        int p,c;
        if(!SearchHash(key,p,c)){
            if(c/this->size)<0.5)
            {
                this->rcd[p].key=key;
                this->tag[p]=-1;
                return true;
            }
            else recreateHash(H);  //扩展Hash表
        }
        return false;
    }

    void printHash()
    {
        int i;
        print("key:  ");
        for (i = 0; i < this->size; i++)
            printf("%3d ", this->rcd[i].key);
        printf("\n");
        printf("tag : ");
        for (i = 0; i < this->size; i++)
            printf("%3d ", this->tag[i]);
        printf("\n\n");
    }

private:
    RcdType* rcd;  //key区域
    int size;      //hash空间大小 
    int *tag;


    std::vector<T> hashsize;
    int index;
    int count;     //hash占用空间的大小
};