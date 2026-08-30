class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
       sort(nums.begin(), nums.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] < b[1]; 
    });
    int n = nums.size();
    if (n==1)return 0;
    int left =0, right =1;
    int res = 0;
    while (right<nums.size()) {
        if (nums[left][1]>nums[right][0]) {
            res++;
            right++;
            continue;
        }
        left=right;
        right++;
    }
    return res;
    }
};