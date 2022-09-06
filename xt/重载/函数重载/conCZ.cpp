#include <iostream>

class Car 
{
public:
    Car()
    {
        std::cout<<"生产减配版本的汽车"<<std::endl;
    }

    Car(int a)
    {
        std::cout<<"生产2222"<<std::endl;
    }
};