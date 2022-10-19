
//冒泡排序
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */
    vector<int> MySort(vector<int>& arr) {
        int tmp;
        for(int i=0;i<arr.size()-1;i++)
        {
            for(int j=i;j<arr.size();j++)
            {
                if(arr[i]>arr[j])
                {
                    tmp=arr[j];
                    arr[j]=arr[i];
                    arr[i]=tmp;
                }
            }
        }
        return arr;
    }
};