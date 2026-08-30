class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
    unordered_map<int, int> freq;
    int res = 0;
    int left =0, right = 0;
    while (right<n) {
        freq[nums[right]]++;
        while (freq[nums[right]]>k) {
            freq[nums[left]]--;
            if (freq[nums[left]]==0)
                freq.erase(nums[left]);
            left++;
        }
        // Valid array
        int windowLength = right - left+1;
        res = max(windowLength, res);
        right++;
    }
    return res;
    }
};