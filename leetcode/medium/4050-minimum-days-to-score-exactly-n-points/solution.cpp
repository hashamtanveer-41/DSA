class Solution {
public:
   vector<int> dp;
int solve (int n) {
    if (n==0)return 0;
    if (dp[n]!=-1)
        return dp[n];
    int ans = 1e9;
    for (int i=1; (i*(i+1)/2)<=n; i++) {
        int point = i*(i+1)/2;
        ans = min(ans, i+1+solve(n-point));
    }
    return dp[n] = ans;
}
int minDays(int n) {
    dp.assign(n+1, -1);
    return solve(n)-1;
}
};