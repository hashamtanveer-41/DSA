class Solution {
public:
int calculateClimbStairs(int n,const vector<int>& costs, int j,vector<int>& dp){
    if (j>(n))
        return 1e8;
    if (j==n) {
        return 0;
    }
    if (dp[j]!=-1)return dp[j];
    int c1 = (j+1<=n?costs[j]:0)+calculateClimbStairs(n, costs,j+1, dp)+1;
    int c2 = (j+2<=n?costs[j+1]:0)+calculateClimbStairs(n, costs,  j+2, dp)+4;
    int c3 = (j+3<=n?costs[j+2]:0) + calculateClimbStairs(n, costs, j+3, dp)+9;
    return dp[j]= min(c1, min(c2, c3));
}
int climbStairs(int n, vector<int>& costs) {
    vector<int> dp(n+1,-1);
    return calculateClimbStairs(n,costs,0, dp);
}
};