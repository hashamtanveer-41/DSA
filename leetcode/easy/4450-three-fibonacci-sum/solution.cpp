class Solution {
public:
    bool threeFibonacciSum(int n) {
        if(n<2)return false;
        if(n==2)return true;
        int one = 0;
        int two = 1;
        int three = 1;
        int sum = 2;
        while(sum<=n){
            int temp = three;
            three = two + three;
            one = two;
            two = temp;
            sum = one + two + three;
            if(sum==n)return true;
        }
        return false;
    }
};