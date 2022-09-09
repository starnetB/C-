class Solution {
private:
    static int count;
public:
    int jumpFloor(int number) {
       
//         if(number==1)
//         {
//             count++;
//             return count;
//         }
//         if(number==2)
//         {
//             count=count+2;
//             return count;
//         }
//         if(number>1)
//         {
//             jumpFloor(number-1);
//         }
//         if(number>2)
//         {
//             jumpFloor(number-2);
//         }
//         return count;
        if(number<=1) return 1;
        return jumpFloor(number-1)+jumpFloor(number-2);
    }
};

int Solution::count=0;
