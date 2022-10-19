class Solution {
public:
    /**
     * 反转字符串
     * @param str string字符串 
     * @return string字符串
     */
    Solution(){}
    Solution(const std::string& str):source_(str){}
    
    string solve(string str){
        int len=str.length();
        std::string result="";
        for(size_t i=0;i<len;i++)
        {
            result.push_back(str.at(len-i-1));
        }
        return result;
    }
private:
    std::string source_;
};

