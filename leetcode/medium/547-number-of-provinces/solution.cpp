class Solution {
public:
    void dfsVI(vector<vector<int>>& nums, vector<int>& vis, int i, int n) {
    if (i==n)return;
    vis[i] = 1;
    for (int j=0; j<nums[i].size();j++) {
        if (vis[j]==-1 && nums[i][j]==1)
            dfsVI(nums, vis, j, n);
    }
} 
int findCircleNum(vector<vector<int>>& isConnected) {
   int n = isConnected.size();
    vector<int> vis(n, -1);
    int res =0;
    for (int i=0; i<n; i++) {
        if (vis[i]==-1) {
            dfsVI(isConnected, vis, i,n);
            res++;            
        }
    }
    return res;
}
};