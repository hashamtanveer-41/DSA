class Solution {
public:
    bool checkDivisibility(int n) {
       long long sum = 0;
       long long prod = 1;
       int val = n;
       while(val>0){
            int dig = val%10;
            sum += dig;
            prod *= dig;
            val = val/10;
       } 
       return n%(sum+prod)==0;
    }
};