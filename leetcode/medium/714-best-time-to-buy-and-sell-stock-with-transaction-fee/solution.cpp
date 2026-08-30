class Solution {
public:
    int fun11(vector<int>& a,int n,  int i, int k, vector<vector<int>>& dp, int fee) {
    if (i==n)return 0;
    if (k==0)return 0;
    if (dp[i][k]!=-1)return dp[i][k];
    if (k%2==0) {
        // Buy
        int c1 = fun11(a, n, i+1, k-1, dp, fee) - a[i]-fee;
        int c2 = fun11(a, n, i+1, k, dp, fee);
        return dp[i][k] = max(c1, c2);
    }else {
        // Sell
        int c1 = fun11(a, n, i+1, 2, dp, fee) + a[i];
        int c2 = fun11(a, n, i+1, k, dp, fee);
        return dp[i][k] = max(c1, c2);
    }
}
int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    int k = 2;
    vector<vector<int>> dp(n+1);
    for (int i=0; i<=n; i++) {
        vector<int> t(k+1, -1);
        dp[i] = t;
    }
    int ans =  fun11(prices, n, 0, k, dp, fee);
    return ans;
}
};