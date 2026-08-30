class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
    int reach = 0;
    for (int i=0; i<n; i++) {
        if (reach>=n-1)return true;
        if (reach<i)return false;
        reach = max(reach, nums[i]+i);
    }
    return true;
    }
};