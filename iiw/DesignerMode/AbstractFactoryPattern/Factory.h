#ifndef FACTORY_H
#define FACTORY_H

#include <product.h>

class Factory{
public:
    enum FACTORY_TYPE{
        BENZ_FACTORY,
        BMW_FACTORY,
        AUDI_FACTORY
    };

    virtual ICar* CreateCar()=0;
    virtual IBike* CreateBike()=0;
    static Factory* CreateFactory(FACTORY_TYPE type);
};
#endif