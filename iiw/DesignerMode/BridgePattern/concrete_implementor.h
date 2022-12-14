#ifndef CONCRETE_IMPLEMENTOR_H
#define CONCRETE_IMPLEMENTOR_H

#include "implementor.h"
#include <iostream>

class Light:public IEletricalEquipment
{
public:
    //Turn on the lights
    virtual void PowerOn() override
    {
        std::cout << "Light is on." << std::endl;
    }

    virtual void PowerOff() override
    {
        std::cout << "Light is off." << std::endl;
    }
};

class Fan:public IEletricalEquipment
{
public:
    virtual void PowerOn() override
    {
        std::cout << "Fan is on." << std::endl;
    }

    // Turn off the fan
    virtual void PowerOff() override
    {
        std::cout << "Fan is off." << std::endl;
    }
};

#endif