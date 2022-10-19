#include <ReplaceAlgorithm.h>

template<class RA>
class Cache_T
{
private:
    RA m_ra;
public:
    Cache_T(){}
    ~Cache_T(){}
    void Replace(){ m_ra.Replace();}
};

int main()
{
    Cache_T<Random_ReplaceAlgorithm> cache_t;
    cache_t.Replace();
    return 0;
}