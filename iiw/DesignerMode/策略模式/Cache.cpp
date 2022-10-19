#include<ReplaceAlgorithm.h>

class Cache{
private:
    ReplaceAlgorithm *m_ra;
public:
    Cache(ReplaceAlgorithm *ra){m_ra=ra;}
    ~Cache(){delete m_ra;}
    void Replace(){m_ra->Replace();}
};

int main()
{
    Cache cache(new LRU_ReplaceAlgorithm());
    cache.Replace();
    return 0;
}
