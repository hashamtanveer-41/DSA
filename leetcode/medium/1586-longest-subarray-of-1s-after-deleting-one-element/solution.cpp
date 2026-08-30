class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
    int left = 0, right = 0, res =0;
    int power = 1;
    while (right<n) {
        if (nums[right]==0)
            power--;
        while (power<0) {
                if (nums[left]==0)power = false;
                left++;
        }
        res = max(res, (right - left));
        right++;
    }
    return res;
    }
};