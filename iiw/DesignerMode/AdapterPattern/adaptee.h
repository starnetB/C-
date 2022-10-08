//适配器模式，将一个接口转换成客户希望的另一个接口，完成适配
//你想使用一个已经存在的类，而它的接口不符合你的需求
//你想创建一个可以复用的类，改类可以与其他不相关的类或不可预见(可能不兼容)的类协同工作
//你想使用一些已经存在的子类，但是不可能对每一个都进行子类化以匹配它们的接口

#ifndef ADAPTEE_H
#define ADAPTEE_H
#include <iostream>

//你要让这个是适配你的市场
class OwnCharger
{
public:
    void ChargeWithFeetFlat()
    {
        std::cout<<"OwnCharger::ChargeWithFeetFlat"<<std::endl;
    }
};


#endif