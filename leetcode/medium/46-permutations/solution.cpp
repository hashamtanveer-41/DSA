class Solution {
public:
    void permutationOfNumbers(vector<vector<int>>& res, vector<int>& nums, vector<int>& temp,vector<int>& vis, int currVal, int n) {
    temp.push_back(currVal);
    if (temp.size()==n) {
        res.push_back(temp);
        return;
    }
    for (int i=0; i<n; i++) {
        if (vis[i]==-1) {
            vis[i]=1;
            permutationOfNumbers(res, nums, temp, vis, nums[i], n);
            temp.pop_back();
            vis[i]=-1;
        }
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> res;
    for (int i=0; i<n; i++) {
        vector<int> temp;
        vector<int> vis(n, -1);
        vis[i]=1;
        permutationOfNumbers(res, nums, temp, vis, nums[i], n);
    }
    return res;
}
};