#include <iostream>


inline int functionName(int first,int second);

int functionName(int first,int second);

inline int functionName(int first,int second)
{
    return 0;
}

class A{
    int doA();
};

inline int A::doA(){return 0;}