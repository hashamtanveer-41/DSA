class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
    int left = 0, right = 0;
    int res =0;
    while (right<n) {
        if (nums[right]==0)k--;
        while (k<0) {
            if (nums[left]==0)k++;
            left++;
        }
         res = max(res, (right - left + 1));
        right++;
    }
    return res;
    }
};