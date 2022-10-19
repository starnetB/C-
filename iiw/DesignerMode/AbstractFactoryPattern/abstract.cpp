#include <Factory.h>
#include <concrete_factory.h>
#include <product.h>
#include <concrete_procuct.h>
#include <iostream>

int main()
{
    Factory* factory=new BenzFactory();
    ICar *car=factory->CreateCar();
    IBike *bike=factory->CreateBike();
    std::cout<<car->Name()<<std::endl;
    std::cout<<bike->Name()<<std::endl;

    factory=new BmwFactory();
    car=factory->CreateCar();
    bike=factory->CreateBike();
    std::cout<<car->Name()<<std::endl;
    std::cout<<bike->Name()<<std::endl;

    factory=new AudiFactory();
    car=factory->CreateCar();
    bike=factory->CreateBike();
    std::cout<<car->Name()<<std::endl;
    std::cout<<bike->Name()<<std::endl;
}