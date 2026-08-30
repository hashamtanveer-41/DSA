class Solution {
public:
    int climbStairs(int n) {
        if (n==1 || n==2)return n;
        int last = 0;
        int secondLast = 1;
        for(int i = n-1; i>=0; i--){
            int ans = last + secondLast;
            last = secondLast;
            secondLast =ans;
        }
        return secondLast;
    }
};