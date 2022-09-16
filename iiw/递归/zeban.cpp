//折半查找


//使用递归的思路

#include<iostream>

using namespace std;

int HalfSearch(int *array,int start,int end,int target)
{
    int len=end-start;
    int mid=(int)((end+start)/2);
    int result;
    // for(int i=start;i<=end;i++)
    // {
    //     std::cout<<array[i];
    // }
    // std::cout<<std::endl;

    if(len==0&&array[start]!=target)
    {
        result=-1;
        std::cout<<result<<std::endl;
        return result;
    }

    if(array[mid]==target)
    {
        result=mid;
        std::cout<<result<<std::endl;
        return result;
    }

    if(array[mid]<target)
    {
        result=HalfSearch(array,mid+1,end,target);
    }else{
        result=HalfSearch(array,start,mid,target);
    }
    return result;
}
//迭代的思路来解决问题的话
int HalfSearchAll(int array[],int start,int end,int target)
{
    int result;
    while (start<=end)
    {
        int mid=(int)((start+end)/2);

        if(array[mid]>target)
        {
            start=start;
            end=mid;
        }
        if(array[mid]==target)
        {
            result=mid;
            break;
        }

        if(array[mid]<target)
        {
            start=mid+1;
            end=end;
        }
    }
    return result;
}
int main()
{
    int *array=new int[100];
    
    for(int i=0;i<10;i++)
    {
        array[i]=i;
    }
    //采用递归的思路
    int result=HalfSearch(array,0,9,99);
    
    //采用迭代的思路
    int result2=HalfSearchAll(array,0,9,3);
    std::cout<<result2<<std::endl;
    
}