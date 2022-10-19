#ifndef CON_PRODUCT_H
#define CON_PRODUCT_H

#include <product.h>

class BenzCar:public ICar 
{
public:
    string Name()
    {
        return "Benz Car";
    }
};

class BmwCar:public ICar
{
public:
    string Name()
    {
        return "Bmw Car";
    }
};

class AudiCar:public ICar 
{
public:
    string Name()
    {
        return "Audi Carr";
    }
};


/* Bicycle*/
//Benz
class BenzBike:public IBike
{
public:
    string Name()
    {
        return "Benz Bike";
    }
};

//BMW
class BmwBike:public IBike
{
public:
    string Name()
    {
        return "Bmw Bike";
    }
};

//Audi 
class AudiBike:public IBike
{
public:
    string Name()
    {
        return "Audi Bike";
    }
};

#endif