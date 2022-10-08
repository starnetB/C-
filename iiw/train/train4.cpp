#ifndef TRAIN5_H
#define TRAIN5_H

#include <iostream>

class IeleEquipment
{
public:
    IeleEquipment(){}
    virtual void optionOn()=0;
    virtual void optionOff()=0;
};
class ISwitch
{
public:
    ISwitch(IeleEquipment* ee){m_pEe=ee;}

    virtual ~ISwitch(){}
    virtual void On()=0;
    virtual void Off()=0;
protected:
    IeleEquipment* m_pEe;
};

class OldSwitch:public ISwitch
{
public:
    OldSwitch(IeleEquipment *ee):ISwitch(ee){}
    virtual void On() override
    {
        std::cout<<"use old Switch!"<<std::endl;
        this->m_pEe->optionOn();
    }

    virtual void Off() override
    {
        std::cout<<"use old switch!"<<std::endl;
        this->m_pEe->optionOff();
    }
};

class NewSwitch:public ISwitch
{
public:
    NewSwitch(IeleEquipment *ee):ISwitch(ee)
    {}

    virtual void On() override
    {
        std::cout<<"use new Switch!"<<std::endl;
        this->m_pEe->optionOn();
    }

    virtual void Off() override
    {
        std::cout<<"use new switch!"<<std::endl;
        this->m_pEe->optionOff();
    }
};

class Light:public IeleEquipment
{
public:
    Light(){}
    virtual void optionOn() override
    {
        std::cout<<"Light on!"<<std::endl;
    }

    virtual void optionOff() override
    {
        std::cout<<"Light off!"<<std::endl;
    }
};

class Radio:public IeleEquipment
{
public:
    Radio(){}

    virtual void optionOn() override
    {
        std::cout<<"Radio On!"<<std::endl;
    }

    virtual void optionOff() override
    {
        std::cout<<"Radio On!"<<std::endl;
    }
};

int main()
{
    IeleEquipment* light=new Light();
    IeleEquipment* radio=new Radio();

    ISwitch* il=new OldSwitch(light);
    ISwitch* ir=new OldSwitch(radio);

    il->On();
    il->Off();

    ir->On();
    ir->Off();

    ISwitch* inl=new NewSwitch(light);
    ISwitch* inr=new NewSwitch(radio);
    inl->On();
    inl->On();
    inr->Off();
    inr->Off(); 
}
#endif