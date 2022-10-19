#include <iostream>

class A
{
public:
    int x;
    int y;
private:
    void pp()
    {
        std::cout<<"11111111"<<std::endl;
    }
};


// 堆里面开辟
int main()
{
    A *pa=(A *)malloc(sizeof(A));
    if(pa!=NULL)
    {
        pa->x=3;
        pa->y=4;
        std::cout<<pa->x<<std::endl;
        std::cout<<pa->y<<std::endl;
    }

    free(pa);
    return 0;
}