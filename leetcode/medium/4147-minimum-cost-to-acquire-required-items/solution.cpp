class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long val = max(need1, need2);
        long long cB = costBoth * val;
        long long c1 = (1LL*cost1)*(1LL*need1);
        long long c2 = (1LL*cost2)*(1LL*need2);
        long long c = c1+c2;
        long long c3;
        if(need1<need2){
            long long a = (1LL*need1)*(1LL*costBoth);
            long long b = (1LL*cost2)*(need2-need1);
            c3 = a+b;
        }else{
            long long a = (1LL*need2)*(1LL*costBoth);
            long long b = (1LL*cost1)*(need1-need2);
            c3 = a+b;
        }
        return min(c, min(c3, cB));
    }
};