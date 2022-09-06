//冒泡排序
//O(n)空间复杂度
//时间复杂度O(n2)

class Solution {
public:
    //归并部分
    //// 归并排序：把数据分为两段，从两段中逐个选最小的元素移入新数据段的末尾。可从上到下或从下到上进行。
    template <typename T>
    void MergeSort(vector<T> &source,vector<T> &reg,int start,int end)
    {
        //reg.clear();
        if(start>=end)
        {
            return ;
        }
        
        int len=end-start;
        int mid=(len>>1)+start;
        int startLeft=start,endLeft=mid;
        int startRight=mid+1,endRight=end;
        int k=start;
        
        MergeSort(source,reg, startLeft,endLeft);
        MergeSort(source,reg, startRight,endRight);
        
        while(startLeft<=endLeft &&startRight<=endRight)
        {
            if(source[startLeft]>source[startRight])
            {
                reg[k++]=source[startLeft++];
            }else
            {
                reg[k++]=source[startRight++];
            }
        }
        while(startLeft<=endLeft)
        {
            reg[k++]=source[startLeft++];
        }
        while(startRight<=endRight)
        {
            reg[k++]=source[startRight++];
        }
        
        for(int k=start;k<=end;k++)
        {
            source[k]=reg[k];
        }
        printvec(reg);
    }
    
    template <typename T>
    void printvec(vector<T> arrd)
    {
        for(int i=0;i<arrd.size();i++)
        {
            std::cout<<"  "<<arrd[i];
        }
        std::cout<<std::endl;
    }
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */
    vector<int> MySort(vector<int>& arr) {
       //归并排序
        int start=0;
        int end=arr.size()-1;
        vector<int> reg(arr.size(),0);
        MergeSort<int>(arr, reg, start,end);
        return arr;
    }
};