#ifndef REPLACEALGORITHM_H
#define REPLACEALGORITHM_H

#include <iostream>

using namespace std;

class ReplaceAlgorithm
{
public:
    virtual void Replace()=0;
};

class LRU_ReplaceAlgorithm:public ReplaceAlgorithm
{
public:
    void Replace();
};

class FIFO_ReplaceAlgorithm:public ReplaceAlgorithm
{
public:
    void Replace();
};

class Random_ReplaceAlgorithm:public ReplaceAlgorithm
{
public:
    void Replace();
};

#endif