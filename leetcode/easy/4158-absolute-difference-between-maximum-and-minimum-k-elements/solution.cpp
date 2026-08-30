class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
     int larSum = 0, smallSum = 0;
    int left = 0, right = nums.size()-1;
    sort(nums.begin(), nums.end());
    while (k--) {
        larSum += nums[right];
        right--;
        smallSum += nums[left];
        left++;
    }
    return abs(larSum - smallSum);   
    }
};