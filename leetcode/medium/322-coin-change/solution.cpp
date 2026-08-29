class Solution {
public:
   int findCoinChange(vector<int>& coins, int target, long long currSum, int idx, vector<vector<long long>>& dp) {
    if (currSum>target || idx==coins.size())return 1e8;
    if (currSum == target)return 0;
    if (dp[idx][currSum]!=-1)return dp[idx][currSum];
    int c3 = 1+findCoinChange(coins, target, currSum+coins[idx], idx, dp);
    int c2 = findCoinChange(coins, target, currSum , idx+1, dp);
    return dp[idx][currSum] = min(c2, c3);
}
int coinChange(vector<int>& coins, int amount) {
    vector<vector<long long>> dp(coins.size()+1, vector<long long>(amount+1, -1)); 
    int ans =  findCoinChange(coins, amount, 0, 0 ,dp);
    if (ans>=1e8)return -1;
    return ans;
}
};