
// 方法：哈希表+双向链表（推荐使用）
// 知识点1：哈希表

// 哈希表是一种根据关键码（key）直接访问值（value）的一种数据结构。而这种直接访问意味着只要知道key就能在O(1)O(1)O(1)时间内得到value，因此哈希表常用来统计频率、快速检验某个元素是否出现过等。

// 知识点2：双向链表

// 双向链表是一种特殊的链表，它除了链表具有的每个节点指向后一个节点的指针外，还拥有一个每个节点指向前一个节点的指针，因此它可以任意向前或者向后访问，每次更改节点连接状态的时候，需要变动两个指针。

// 思路：

// 插入与访问值都是O(1)O(1)O(1)，没有任何一种数据结构可以直接做到。

// 于是我们可以想到数据结构的组合：访问O(1)O(1)O(1)很容易想到了哈希表；插入O(1)O(1)O(1)的数据结构有很多，但是如果访问到了这个地方再选择插入，且超出长度要在O(1)O(1)O(1)之内删除，我们可以想到用链表，可以用哈希表的key值对应链表的节点，完成直接访问。但是我们还需要把每次访问的key值节点加入链表头，同时删掉链表尾，所以选择双向链表，便于删除与移动。

// 于是我们的方法就是哈希表+双向链表。
#include<iostream>
#include<unordered_map>

using namespace std;

class Node{
public:
    int key;
    int val;
    Node *pre;
    Node *next;
    
public:
    Node(){}
    Node(int key,int val):key(key),val(val),pre(NULL),next(NULL){};
};

class Solution {
public:
    int size=0;
    Node *head=NULL;
    Node *tail=NULL;
    //哈希表记录key值
    unordered_map<int, Node*> mp;
    
    
    Solution(int capacity){
        this->size=capacity;
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->pre=head;
    }
    
    
    
    void insertFrist(Node *node)
    {
        node->next=head->next;
        node->pre=head;
        
        head->next=node;
        node->next->pre=node;
    }
    
    void removeTail()
    {
    
        int ret=mp.erase(tail->pre->key);
        std::cout<<ret<<std::endl;
        
        tail->pre->pre->next=tail;
        tail->pre=tail->pre->pre;
        //std::umap 线程安全原因，如果map没有擦除，就会导致tail没法修改
//         int ret=mp.erase(tail->pre->key);
//         std::cout<<ret<<std::endl;
       
    }
    
    void movetoHead(Node *node)
    {
        if (node->pre==head)
        {
            return;
        }
        node->pre->next=node->next;
        node->next->pre=node->pre;
        
        insertFrist(node);
    }
    
    int get(int key) {
        int res=-1;
        if(mp.find(key)==mp.end())
        {
            return res;
        }else{
            res=mp[key]->val;
            movetoHead(mp[key]);
            return res;
        }
    }
    
    void set(int key, int value){
         if(mp.find(key)==mp.end())
         {
             Node *node=new Node(key,value);
             mp[key]=node;
             if(size<=0)
             {
                 removeTail();
             }else
             {
                 size--;
             }
             insertFrist(node);
         }else{
             mp[key]->val=value;
             movetoHead(mp[key]);
         }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* solution = new Solution(capacity);
 * int output = solution->get(key);
 * solution->set(key,value);
 */