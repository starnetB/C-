#include <iostream>
#include <vector>
#include <map>
using namespace std;

//数组全排列
static vector<int> tmpvec;

std::map<int,std::vector<int>> function(std::vector<int> stl)
{
    std::map<int,std::vector<int>> nw;
    for(int i=0;i<stl.size();i++)
    {
        std::vector<int> table;
        for(int k=0;k<stl.size();k++)
        {
            if(k!=i)
                table.push_back(stl[k]);
        }
        nw.insert(std::make_pair(i,table));
    }
    return nw;
}

int allsize(int n)
{
    if(n==1)
        return 1;
    return n*allsize(n-1);
}


void printvector(std::vector<int> dd)
{
    for(int i=0;i<dd.size();i++)
    {
        std::cout<<" "<<dd[i];
    }
    std::cout<<std::endl;
}

void result(std::map<int,vector<int>> stl,
                    std::vector<int> source,
                    std::vector<int> last,
                    std::vector<vector<int>> &output,
                    bool init)
{
  
    for(auto it:stl)
    {
        vector<int> dd;
        auto ll=function(it.second);
        if(init==false)
            dd.insert(dd.end(),source.begin(),source.end());

        dd.push_back(last[it.first]);
        if(it.second.size()==1)
        {
            dd.push_back(it.second[0]);
            // printvector(dd);
            output.push_back(dd);
        }
        else
            result(ll,dd,it.second,output,false);
    }
    
}


int main()
{
    vector<int> a={1,2,3,4};
    auto l=function(a);
    for(auto it:l)
    {
        std::cout<<"first"<<it.first+1<<std::endl;
        for(int k=0;k<it.second.size();k++)
            std::cout<<":: second  "<<it.second[k]<<std::endl;
    }

    vector<int> d;
    // int nn=allsize(a.size());
    // int n=a.size();
    // std::cout<<nn<<std::endl;
    // std::cout<<n<<std::endl;
    // std::vector<vector<int>> output(nn, vector<int>(n, 0));
    // std::cout<<output.size()<<std::endl;
    // vector<int> dd(3,0);
    // printvector(dd);
    std::vector<vector<int>> output;
    result(l,d,a,output,true);   

    for(int i=0;i<output.size();i++)
    {
        printvector(output[i]);
    }
}