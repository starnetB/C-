#include <ReplaceAlgorithm.h>

enum RA{LRU,FIFO,RANDOM};


class Cache_S
{
private:
    ReplaceAlgorithm *m_ra;
public:
    Cache_S(enum RA ra)
    {
        if(ra==LRU)
            m_ra=new LRU_ReplaceAlgorithm();
        else if(ra==FIFO)
            m_ra=new FIFO_ReplaceAlgorithm();
        else if(ra=RANDOM)
            m_ra=new Random_ReplaceAlgorithm();
        else
            m_ra=NULL;
    }

    ~Cache_S(){delete m_ra;}
    void Replace(){m_ra->Replace();}
};

int main()
{
    Cache_S cache_s(LRU);
    cache_s.Replace();
    return 0;
}