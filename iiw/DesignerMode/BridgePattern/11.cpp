#include <iostream>
#include <memory>

using namespace std;

class Equipment
{
public:
    Equipment(){}
    ~Equipment(){}
    virtual void On()=0;
    virtual void Off()=0;
};

class OE:public Equipment
{
public:
    virtual void On() override
    {
        std::cout<<"Oe on"<<std::endl;
    }

    virtual void Off() override
    {
        std::cout<<"Oe off"<<std::endl;
    }

};

class WE:public Equipment
{
public:
    virtual void On() override
    {
        std::cout<<"We on"<<std::endl;
    }

    virtual void Off() override
    {
        std::cout<<"We off"<<std::endl;
    }
};

class ISwitch
{
public:
    ISwitch(std::shared_ptr<Equipment> eq):EqPtr(eq){
    }
    ~ISwitch(){}

    virtual void On()=0;

    virtual void Off()=0;
protected:
    std::shared_ptr<Equipment> EqPtr;
    
};

class OneSwitch:public ISwitch
{
public:
    OneSwitch(std::shared_ptr<Equipment> eq):ISwitch(eq){}

    virtual void On() override{
        std::cout<<"oneSwitch on"<<std::endl;
        EqPtr->On();
    }

    virtual void Off() override{
        std::cout<<"oneSwitch off"<<std::endl;
        EqPtr->Off();
    }
};

class TwoSwitch:public ISwitch
{
public:
    TwoSwitch(std::shared_ptr<Equipment> eq):ISwitch(eq){}

      virtual void On() override{
        std::cout<<"oneSwitch on"<<std::endl;
        EqPtr->On();
    }

    virtual void Off() override{
        std::cout<<"oneSwitch off"<<std::endl;
        EqPtr->Off();
    }
};

int main()
{
    OE* oe=new OE();
    std::shared_ptr<Equipment> oee(oe);
    
    WE* we=new WE();
    std::shared_ptr<Equipment> wee(we);

    std::shared_ptr<ISwitch> TS=std::make_shared<TwoSwitch>(oee);
    TS->Off();
    TS->On();

    std::shared_ptr<ISwitch> OS=std::make_shared<OneSwitch>(wee);
    OS->Off();
    OS->On();
}