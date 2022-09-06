//返回数组中最小的n个数
//空间复杂度O(n)
//时间复杂度O(nlogn)
class Solution {
private:
    std::priority_queue<int> p;
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        for(auto x:input)
        {
            p.push(x);
            if(p.size()>k)
            {
                p.pop();
            }
        }
        
        if(p.size()<k)
        {
            return input;
        }
        
        input.clear();
        
        while(!p.empty()){
            input.push_back(p.top());
            //std::cout<<p.top()<<std::endl;
            p.pop();
        }
        return input;
    }
};