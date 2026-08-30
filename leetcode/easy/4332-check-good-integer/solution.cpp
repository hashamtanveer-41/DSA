class Solution {
public:
    bool checkGoodInteger(int n) {
        int res =0, digitSum=0, squareSum=0, mod;
        while(n>0){
            int digit = n % 10;
            digitSum += digit;
            squareSum += (digit*digit);
            n=n/10;
        }
        res = squareSum - digitSum;
        if(res>=50)return true;
        return false;
    }
};