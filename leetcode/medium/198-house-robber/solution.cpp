class Solution {
public:
    int fun9(vector<int>& nums, int n, int i, int free,vector<vector<int>>& dp) {
    if (n==i)return 0;
    if (free==0)
        return dp[i][0] = fun9(nums, n, i+1, 1, dp);
    if (dp[i][1]!=-1)
        return dp[i][1];
    int c1 = nums[i] + fun9(nums, n, i+1, 0, dp);
    int c2 = fun9(nums, n, i+1, 1, dp);
    return dp[i][1] = max(c1, c2);
}

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n);
    for (int i=0; i< n; i++) {
        vector<int> t(2, -1);
        dp[i] = t;
    }
    return fun9(nums, n, 0, 1, dp);
}
};