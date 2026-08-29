class Solution {
public:
  int dp[103][103] ;
    int fun13(vector<int>& cuts, int i, int j) {
    if (i>j)return 0;
    if(dp[i][j] != -1){
            return dp[i][j] ;
        }
    int res = INT_MAX;
    for (int k=i; k<=j; k++) {
        int cost = cuts[j+1]-cuts[i-1];
        int r = cost + fun13(cuts, i,k-1)+fun13(cuts, k+1, j);
        res = min(res, r);
    }
    return dp[i][j] = res;
}
int minCost(int n, vector<int>& c) {
    vector<int> cuts;
    cuts.push_back(0);
    for (int i=0; i<c.size();i++)
        cuts.push_back(c[i]);
    sort(cuts.begin(), cuts.end());
    cuts.push_back(n);
    memset(dp, -1, sizeof(dp)) ;
    int s = cuts.size();
    return fun13(cuts, 1, s-2);
}
};