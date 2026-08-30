class Solution {
public:
bool isSubsetSum(vector<int>& arr, int sum) {
    // code here
    int n = arr.size();
    vector<vector<int>> dp(n+1);
    for (int i=0; i<=n ;i++) {
        vector<int> t(sum+1, -1);
        dp[i] = t;
    }
    for (int j=0; j<=sum; j++)
        dp[n][j] = 0;
    dp[n][0] = 1;
    for (int i=n-1; i>=0; i--) {
        for (int j=0; j<=sum; j++) {
            if (arr[i]>j)
                dp[i][j] = dp[i+1][j];
            else
                dp[i][j] = dp[i+1][j] || dp[i+1][j-arr[i]];
        }
    }
    return dp[0][sum];
}
    bool canPartition(vector<int>& nums) {
    int sum =0;
    for (int num: nums)
        sum+=num;
    if (sum%2==1)return false;
    return isSubsetSum(nums, sum/2);
}
};