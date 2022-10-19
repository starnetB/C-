#include <iostream>

using namespace std;

#ifndef SAFF_DELETE
#define SAFF_DELETE(p) {if(p){delete(p);(p)=NULL;}}
#endif

class COM
{
public:
    COM(){}
    ~COM(){}

    void doE()
    {
        std::cout<<"ddddddddddd"<<std::endl;
    }
};

class Socket
{
public:
    Socket(){}
    ~Socket(){}

    virtual void charge()=0;
};


class IPSocket:public Socket
{
public:
    IPSocket():om_(new COM()){}
    ~IPSocket(){
        SAFF_DELETE(om_);
    }

    void charge(){
       om_->doE();
    }
private:
   COM* om_;  
};

int main()
{
    Socket* ip=new IPSocket();
    ip->charge();
}
