#ifndef IMPLEMENTOR_H
#define IMPLEMENTOR_H

class IEletricalEquipment
{
public:
    virtual ~IEletricalEquipment(){}
    virtual void PowerOn()=0;
    virtual void PowerOff()=0;
};

#endif