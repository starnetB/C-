#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include <list>


#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=nullptr;} }
#endif


class IObserver
{
public:
    virtual void Update(float price)=0;
};

class ConcreteObserver:public IObserver
{
public:
    ConcreteObserver(std::string name){ m_strName=name;}
    void Update(float price){
        std::cout<<m_strName<<"_price"<<price<<std::endl;
    }
private:
    std::string m_strName;
};

class ISubject
{
public:
    virtual void Attach(IObserver *)=0;
    virtual void Detach(IObserver *)=0;
    virtual void Notify()=0;
};

//把价格通知給每个观察者
class ConcreteSubject:public ISubject
{
public:
    ConcreteSubject(){m_fPrice=10.0;}
    void SetPrice(float price)
    {
        m_fPrice=price;
    }

    void Attach(IObserver* observer)
    {
        m_observers.push_back(observer);
    }

    void Detach(IObserver* observer)
    {
        m_observers.remove(observer);
    }

    //通知所有观察者
    void Notify()
    {   
        std::list<IObserver *>::iterator it=m_observers.begin();
        while (it!=m_observers.end())
        {
            (*it)->Update(m_fPrice);
            ++it;
        }

    }
private:
    std::list<IObserver *> m_observers;
    float m_fPrice;
};

int main()
{
    ConcreteSubject *pSubject=new ConcreteSubject();

    IObserver *pObserver1=new ConcreteObserver("Jack Ma");
    IObserver *pObserver2=new ConcreteObserver("Pony");

    pSubject->Attach(pObserver1);
    pSubject->Attach(pObserver2);

    pSubject->SetPrice(12.5);
    pSubject->Notify();

    pSubject->Detach(pObserver2);
    pSubject->SetPrice(15.0);
    pSubject->Notify();

    SAFE_DELETE(pObserver1);
    SAFE_DELETE(pObserver2);
    SAFE_DELETE(pSubject);
}
#endif