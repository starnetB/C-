#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using std::string;

//Car
class ICar
{
public:
    virtual string Name()=0;
};

//Bike Interface
class IBike
{
public:
    virtual string Name()=0;
};

#endif