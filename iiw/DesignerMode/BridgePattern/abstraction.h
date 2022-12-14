#ifndef ABSTRACTION_H
#define ABSTRACTION_H

#include "implementor.h"

class ISwitch
{
public:
    ISwitch(IEletricalEquipment *ee){ m_pEe = ee;}

    virtual ~ISwitch(){}
    virtual void On()=0;
    virtual void Off()=0;
protected:
    IEletricalEquipment* m_pEe;
};


#endif