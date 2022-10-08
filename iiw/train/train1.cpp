#include <iostream>

//工厂模式

class Big
{
public:
   virtual void printBig()=0;
};

class Small
{
public:
    virtual void printSmall()=0;
};

//香蕉公司的产评
class BigBan:public Big
{
    void printBig()
    {
        std::cout<<"Big Ban"<<std::endl;
    }
};

class SmallBan:public Small
{
    void printSmall()
    {
        std::cout<<"Small Ban"<<std::endl;
    }
};

//苹果公司的产品
class BigApp:public Big
{
    void printBig()
    {
        std::cout<<"Big App"<<std::endl;
    }
};

class SmallApp:public Small
{
    void printSmall()
    {
        std::cout<<"Small App"<<std::endl;
    }
};

//橘子工厂产品
class BigOrg:public Big
{
    void printBig()
    {
        std::cout<<"Big org"<<std::endl;
    }
};

class SmallOrg:public Small
{
    void printSmall()
    {
        std::cout<<"Small Org"<<std::endl;
    }
};




//工厂
class Factory
{
public:
    explicit Factory(){}

    enum FactoryType {BAN,APP,ORN};

    virtual Big* createBig()=0;
    virtual Small* createSmall()=0;

    static Factory* createFactory(FactoryType type);
};


//香蕉工厂
class BanFactory:public Factory
{
public:
    explicit BanFactory():Factory(){}

    Big* createBig(){
        return new BigBan();
    }

    Small* createSmall()
    {
        return new SmallBan();
    }
};

//苹果工厂
class AppFactory:public Factory
{
public:
    explicit AppFactory():Factory(){}

    Big* createBig(){
        return new BigApp();
    }

    Small* createSmall()
    {
        return new SmallApp();
    }
};

//橘子工厂
class OrgFactory:public Factory
{
public:
    explicit OrgFactory():Factory(){}

    Big* createBig(){
        return new BigOrg();
    }

    Small* createSmall()
    {
        return new SmallOrg();
    }
};


Factory* Factory::createFactory(FactoryType type)
{
    Factory *pF=nullptr;
    switch (type)
    {
    case BAN:
        pF=new BanFactory();
        break;
    case APP:
        pF=new AppFactory();
        break;
    case ORN:
        pF=new OrgFactory();
        break;
    default:
        break;
    }
    return pF;
}



int main()
{

    Factory* f=Factory::createFactory(BanFactory::BAN);
    Big* b=f->createBig();
    Small* s=f->createSmall();
    b->printBig();
    s->printSmall();

    f=Factory::createFactory(BanFactory::APP);
    b=f->createBig();
    s=f->createSmall();
    b->printBig();
    s->printSmall();

    f=Factory::createFactory(BanFactory::ORN);
    b=f->createBig();
    s=f->createSmall();
    b->printBig();
    s->printSmall();
}   