class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
          int n = nums.size();
    if (n<2)return nums;
    vector<int> ans;
    sort(nums.begin() ,nums.end());
    for (int i=0; i<n; i++) {
        if (nums[i]==-1)continue;
        ans.push_back(nums[i]);
        for (int j= i+1; j<n; j++) {
            if (nums[j]!=-1 && ans[ans.size()-1]!=nums[j]) {
                ans.push_back(nums[j]);
                nums[j]=-1;
            }
        }
        nums[i]=-1;
    }
    return ans;
    }
};