#ifndef DESIGNPATTERN_ADAPTER_H
#define DESIGNPATTERN_ADAPTER_H

#include "adaptee.h"
#include "target.h"

#ifndef SAFF_DELETE
#define SAFF_DELETE(p) {if(p){delete(p);(p)=NULL;}}
#endif

//Power Adapter
class PowerAdapter:public IRussiaSocket
{
public:
    PowerAdapter():m_charger(new OwnCharger()){}
    ~PowerAdapter()
    {
        SAFF_DELETE(m_charger);
    }

    void Charge()
    {
        m_charger->ChargeWithFeetFlat();
    }
private:
    OwnCharger* m_charger;
};

#endif


int main()
{
    IRussiaSocket* ir=new PowerAdapter();
    ir->Charge();
    SAFF_DELETE(ir);
}

//下面是对适配器的理解

//IRsuiaSocket 作为目标，就是用户需要调用的函数
//PowerAdapter->继承IRussiaSocket
//PowerAdapter->关联到OwnCharge
//这里IRusiaSocket的Charge函数就可以使用不同的对象了