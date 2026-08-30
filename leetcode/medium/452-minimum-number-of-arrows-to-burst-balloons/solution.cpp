class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end());
    int n = nums.size();
    if (n==1)return 1;
    int rStart = nums[0][0];
    int rEnd = nums[0][1];
    int res = 1;
    for (int i=1; i<n; i++) {
        if(rEnd >= nums[i][0]) {
            rStart = max(rStart, nums[i][0]);
            rEnd = min(rEnd, nums[i][1]);
        }else {
            res++;
            rStart = nums[i][0];
            rEnd = nums[i][1];
        }
    }
    return res;
    }
};