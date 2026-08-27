class Solution {
public:
    void subsetsOfArray(vector<vector<int>>& res,int idx, vector<int>& nums, vector<int>& temp,vector<int>& vis, int currVal, int n) {
    temp.push_back(currVal);
    res.push_back(temp);
    if (temp.size()==n) {
        return;
    }
    for (int i=idx+1; i<n; i++) {
        if (vis[i]==-1) {
            vis[i]=1;
            subsetsOfArray(res, i, nums, temp, vis, nums[i], n);
            temp.pop_back();
            vis[i]=-1;
        }
    }
}
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> res;
    res.push_back({});
    for (int i=0; i<n; i++) {
        vector<int> temp;
        vector<int> vis(n, -1);
        vis[i]=1;
        subsetsOfArray(res, i, nums, temp, vis, nums[i], n);
    }
    return res;
}
};