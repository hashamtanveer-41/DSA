class Solution {
public:
   int countPairs(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int count = 0;
    int left = 0, right = n-1;
    while (left<right) {
        int sum = nums[left]+nums[right];
        if (sum<target) {
            int len = right - left +1;
            count += len-1; 
            left++;
        }else right--;
    }
    return count;
}
};