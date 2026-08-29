class Solution {
public:
   int findNumSquares (int n, int squares, int currSum,vector<vector<int>>& dp ) {
   if (currSum>n || squares==0)return 1e8;
    if (currSum==n)return 0;
    if(dp[squares][currSum]!=-1)return dp[squares][currSum];
    int c1 = 1+ findNumSquares(n, squares, currSum+(squares*squares), dp);
    int c2 = findNumSquares(n, squares-1, currSum, dp);
    return dp[squares][currSum] = min(c1 ,c2);
}
int numSquares(int n) {
    int squares = 1;
    while ((squares*squares)<=n)squares++;
    squares--;
    vector<vector<int>> dp(squares+1, vector<int> (n+1, -1));
    return findNumSquares(n, squares, 0, dp);

}
};