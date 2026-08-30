class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n+1);
        for(int i=0; i<=n; i++){
            vector<int> t(m+1);
            dp[i]=t;
        }
        dp[n-1][m-1] = 1;
        for(int i=0; i<=n; i++)
            dp[i][m] = 0;
        for(int j=0; j<=m; j++)
            dp[n][j]=0;
        for(int i=n-1;i>=0; i-- ){
            for(int j=m-1; j>=0; j--){
                            if (i==n-1 && j==m-1)continue;

                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};