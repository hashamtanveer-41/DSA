class Solution {
public:
   int combinationSum4(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<unsigned int> dp(amount+1, 0);
    dp[0] = 1;
    for (int i=1; i<=amount; i++) {
        for (int j = 0; j<n; j++) {
            if (coins[j]<=i)
                dp[i] += dp[i - coins[j]];
        }
    }

    return dp[amount];
}
};